create database studb on
(
	name = studb,
	filename = 'c:\my_database\studb_data.mdf',
	size = 3,
	maxsize = 500,
	filegrowth = 10%
)
log on
(
	name = studb_log,
	filename = 'c:\my_database\studb_log.mdf',
	size = 3,
	maxsize = unlimited,
	filegrowth = 1
);