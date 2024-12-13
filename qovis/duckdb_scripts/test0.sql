SET enable_profiling = "QUERY_TREE_OPTIMIZER";
SET profile_output = "/home/youzx/Code/qovis/duckdb-qovis/qovis/test_output";
SET profiling_mode = "DETAILED";

-- SELECT *
-- FROM duckdb_settings()
-- WHERE name = 'log_query_path';

EXPLAIN 
WITH t1 as (SELECT * FROM read_csv_auto('duckdb_benchmark_data/lineitem-split-*.csv'))
SELECT COUNT(*) FROM t1;
