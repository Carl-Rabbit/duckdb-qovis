#!/bin/bash

# path to project root from current file location
PROJECT_ROOT=$(dirname $(dirname $(dirname $(realpath $0))))

# path to debug executable
DEBUG_EXECUTABLE=$PROJECT_ROOT/build/debug/duckdb
DATABASE_FILE_PATH=$PROJECT_ROOT/db_files/bug0.duckdb

cat $PROJECT_ROOT/qovis/duckdb_scripts/load_bug0.sql | $DEBUG_EXECUTABLE $DATABASE_FILE_PATH

echo "Done"