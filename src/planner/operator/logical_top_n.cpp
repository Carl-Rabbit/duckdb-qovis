#include "duckdb/planner/operator/logical_top_n.hpp"

namespace duckdb {

idx_t LogicalTopN::EstimateCardinality(ClientContext &context) {
	auto child_cardinality = LogicalOperator::EstimateCardinality(context);
	if (child_cardinality < limit) {
		return child_cardinality;
	}
	return limit;
}

InsertionOrderPreservingMap<string> LogicalTopN::ParamsToString() const {
	InsertionOrderPreservingMap<string> result;
	result["Limit"] = to_string(limit);
	if (offset > 0) {
		result["Offset"] = to_string(offset);
	}

	string orders_info;
	for (idx_t i = 0; i < orders.size(); i++) {
		if (i > 0) {
			orders_info += "\n";
		}
		orders_info += orders[i].expression->GetName();
	}
	result["Order"] = orders_info;

	return result;
}

} // namespace duckdb
