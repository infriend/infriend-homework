create database testdb on
(
	name = testdb,
	filename = 'c:\my_database\testdb.mdf',
	size = 10,
	maxsize = unlimited,
	filegrowth = 10%

)
log on
(
	name = testdb_log,
	filename = 'c:\my_database\testdb_log.ldf',
	size = 1,
	maxsize = 50,
	filegrowth = 1
);