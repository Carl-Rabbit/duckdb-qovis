#include "duckdb/planner/operator/logical_top_n.hpp"

namespace duckdb {

idx_t LogicalTopN::EstimateCardinality(ClientContext &context) {
	auto child_cardinality = LogicalOperator::EstimateCardinality(context);
	if (limit >= 0 && child_cardinality < idx_t(limit)) {
		return limit;
	}
	return child_cardinality;
}

string LogicalTopN::ParamsToString() const {
	string result;

	result += "ORDERS:\n";
	for (idx_t i = 0; i < orders.size(); i++) {
		if (i > 0) {
			result += "\n";
		}
		result += orders[i].expression->GetName();
	}
	result += "\n";

	result += "LIMIT: " + to_string(limit) + "\n";

	if (offset > 0) {
		result += "OFFSET: " + to_string(offset) + "\n";
	}

	return result;
}

} // namespace duckdb
