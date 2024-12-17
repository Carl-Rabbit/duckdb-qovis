#!/bin/bash

# path to project root from current file location
PROJECT_ROOT=$(dirname $(dirname $(dirname $(realpath $0))))

# path to debug executable
DEBUG_EXECUTABLE=$PROJECT_ROOT/build/debug/duckdb
DATABASE_FILE_PATH=$PROJECT_ROOT/db_files/bug0.duckdb

script=$PROJECT_ROOT/qovis/duckdb_scripts/bug0.sql
output=$PROJECT_ROOT/qovis/results/bug/bug0.v1/bug0.v1.log
echo "Running ${script} and output to ${output}"

mkdir -p $(dirname ${output})

${DEBUG_EXECUTABLE} -no-stdin -init ${script} ${DATABASE_FILE_PATH} > ${output}

echo "Done"