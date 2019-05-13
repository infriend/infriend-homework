create table student
(
	Sno char(6) primary key,
	Sname varchar(24) not null,
	Ssex char(2) not null,
	Sage smallint not null,
	Sdept char(10) not null
)
create table Course
(
	Cno char(2) primary key,
	Cname varchar(24) not null,
	Cpno char(2),
	Ccredit smallint not null
)
create table SC
(
	Sno char(6) not null,
	Cno char(2) not null,
	Grade smallint,
	primary key(Sno, Cno)
);