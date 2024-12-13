#!/bin/bash

# path to project root from current file location
PROJECT_ROOT=$(dirname $(dirname $(dirname $(realpath $0))))

# path to debug executable
DEBUG_EXECUTABLE=$PROJECT_ROOT/build/debug/duckdb
DATABASE_FILE_PATH=$PROJECT_ROOT/ssb_1.duckdb

sqls=$(ls /home/youzx/Code/ssb-dbgen/queries/*.sql)
for sql in ${sqls}
do
    # 2.1.sql -> 2.1
    filename=$(basename ${sql})
    number=${filename%.sql}
    script=${sql}
    output=$PROJECT_ROOT/qovis/results/ssb/ssb.${number}/ssb.${number}.log
    echo "Running ${script} and output to ${output}"

    mkdir -p $(dirname ${output})

    ${DEBUG_EXECUTABLE} -no-stdin -init ${script} ${DATABASE_FILE_PATH} > ${output}
done

echo "Done"