#include "duckdb/planner/operator/logical_limit.hpp"

namespace duckdb {

LogicalLimit::LogicalLimit(BoundLimitNode limit_val, BoundLimitNode offset_val)
    : LogicalOperator(LogicalOperatorType::LOGICAL_LIMIT), limit_val(std::move(limit_val)),
      offset_val(std::move(offset_val)) {
}

vector<ColumnBinding> LogicalLimit::GetColumnBindings() {
	return children[0]->GetColumnBindings();
}

idx_t LogicalLimit::EstimateCardinality(ClientContext &context) {
	auto child_cardinality = children[0]->EstimateCardinality(context);
	switch (limit_val.Type()) {
	case LimitNodeType::CONSTANT_VALUE:
		if (limit_val.GetConstantValue() < child_cardinality) {
			child_cardinality = limit_val.GetConstantValue();
		}
		break;
	case LimitNodeType::CONSTANT_PERCENTAGE:
		child_cardinality = idx_t(double(child_cardinality) * limit_val.GetConstantPercentage());
		break;
	default:
		break;
	}
	return child_cardinality;
}

InsertionOrderPreservingMap<string> LogicalLimit::ParamsToString() const {
	auto result = LogicalOperator::ParamsToString();
	result["Limit"] = to_string(limit_val.GetConstantValue());
	if (offset_val.Type() == LimitNodeType::CONSTANT_VALUE) {
		result["Offset"] = to_string(offset_val.GetConstantValue());
	}
	return result;
}

void LogicalLimit::ResolveTypes() {
	types = children[0]->types;
}

} // namespace duckdb
