#!/bin/bash

# path to project root from current file location
PROJECT_ROOT=$(dirname $(dirname $(dirname $(realpath $0))))

# path to debug executable
DEBUG_EXECUTABLE=$PROJECT_ROOT/build/debug/duckdb
DATABASE_FILE_PATH=$PROJECT_ROOT/db_files/ssb_1.duckdb

# cat ./qovis/duckdb_scripts/load_ssb.sql | ./build/debug/duckdb ssb_1.duckdb
cat $PROJECT_ROOT/qovis/duckdb_scripts/load_ssb.sql | $DEBUG_EXECUTABLE $DATABASE_FILE_PATH

echo "Done"