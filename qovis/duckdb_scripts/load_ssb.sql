.read "/home/youzx/Code/ssb-dbgen/ssb.ddl"
COPY customer FROM '/home/youzx/Code/ssb-dbgen/data-1/customer.tbl';
COPY date_ FROM '/home/youzx/Code/ssb-dbgen/data-1/date.tbl';
COPY lineorder FROM '/home/youzx/Code/ssb-dbgen/data-1/lineorder.tbl';
COPY part FROM '/home/youzx/Code/ssb-dbgen/data-1/part.tbl';
COPY supplier FROM '/home/youzx/Code/ssb-dbgen/data-1/supplier.tbl';