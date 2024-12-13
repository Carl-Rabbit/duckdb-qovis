#!/bin/bash

# path to project root from current file location
PROJECT_ROOT=$(dirname $(dirname $(dirname $(realpath $0))))

# path to debug executable
DEBUG_EXECUTABLE=$PROJECT_ROOT/build/debug/duckdb
DATABASE_FILE_PATH=$PROJECT_ROOT/ssb_1.duckdb

# script=$PROJECT_ROOT/qovis/duckdb_scripts/test0.sql
script=/home/youzx/Code/ssb-dbgen/queries/1.1.sql
output=$PROJECT_ROOT/qovis/results/ssb/ssb.1.1.log

mkdir -p $(dirname ${output})

${DEBUG_EXECUTABLE} -no-stdin -init ${script} ${DATABASE_FILE_PATH} > ${output}

echo "Done"