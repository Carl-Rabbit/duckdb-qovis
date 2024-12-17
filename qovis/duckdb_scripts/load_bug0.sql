CREATE TABLE tbl (col1 INTEGER, col2 INTEGER);
INSERT INTO tbl (col1, col2) SELECT range, range+1 FROM range(1000000);