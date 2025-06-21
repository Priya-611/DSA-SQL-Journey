/**SQL (Structured Query Language) is the language used to communicate with databases — for storing, retrieving, and manipulating data

Imp terms:
Database: a collection of organized information stored electronically. It helps you store, manage, and access data easily. 

Types of db:
DBMS (Database Management System) --> Can store data in files, tables, or other formats/ No relationships enforced between data/ May allow single user

RDBMS (Relational Database Management System) -->Always stores data in tables with rows & columns/ Enforces relationships using keys (Primary Key, Foreign Key)/ Supports Normalization to reduce redundancy/ Designed for multiple users at once
Follows ACID (Atomicity, Consistency, Isolation, Durability) for transactions

NoSQL (Non-relational) stores data in flexible ways (docs, key-value pairs)



SQL commands:
1. DDL (Data Definition Language): define the structure of the database — they create, modify, or delete tables and other database objects.
CREATE(make new database or table) , ALTER(modify existing table), DROP(delete a table or db completely), TRUNCATE(delete all rows)

DDL commands automatically save changes (auto-commit).


2. DML (Data Manipulation Language):  used to add, change, or remove data inside tables — but not the table structure.
INSERT(Add new rows), UPDATE(Change existing data),DELETE(Remove rows)

DML changes can be rolled back (ROLLBACK).


3. DQL (Data Query Language): used to fetch data from tables.
SELECT(get data)

Doesn’t change data, just retrieves it.


4. DCL (Data Control Language): for controlling access to data — giving or taking permissions.
GRANT(Give permissions), REVOKE(Take back permissions)


5. TCL (Transaction Control Language): handle transactions — making sure multiple DML operations succeed or fail together.
COMMIT(Save changes permanently), ROLLBACK(Undo changes), SAVEPOINT(Create a point to roll back to)

DDL-->Structure	
DML-->Data inside	
DQL-->Query(ask for data)	
DCL-->Permissions(controls who can do what)	
TCL-->Transactions




Key words:
Word	Meaning
TABLE -> A container to store rows (like an Excel sheet)
COLUMN -> A single field in the table
ROW -> One record (one student’s info)
PRIMARY KEY -> Uniquely identifies each row
NOT NULL -> Must have a value
VARCHAR	Text
INT	Whole number
DECIMAL	Number with decimal point
DATE	Date
INSERT	Add new rows



Datatypes:
INT Integer — whole numbers, no decimal.
CHAR(n)	— Fixed-length string, always uses exactly n chars
VARCHAR(n) — Variable-length character string , text up to n characters long.
TIME — Time only
DATETIME — Date + time
DATE — Stores a date in YYYY-MM-DD format.
FLOAT —	Approximate decimal
DOUBLE — Bigger approximate decimal
DECIMAL(total digits, digits after decimal point) — Exact decimal number.
BOOLEAN — True or False





CRUD = Create, Read, Update, Delete

Create	to Add new data	[INSERT]
Read	to Get/view data [SELECT]
Update	Change existing data [UPDATE]
Delete	to Remove data	[DELETE]


CREATE DATABASE Make a new database (like a folder to store tables).
CREATE DATABASE SchoolDB;

USE Select a database to work in.
USE SchoolDB;

CREATE TABLE Make a new table with columns.
CREATE TABLE students (
  student_id INT PRIMARY KEY,
  first_name VARCHAR(50),
  age INT
);

SHOW TABLES List all tables in the current database.
SHOW TABLES;

DESCRIBE Show the structure of a table: columns, types, keys.
DESCRIBE students;

SELECT	used to Get data 
SELECT * FROM students;

WHERE used to Filter rows
SELECT * FROM students WHERE age > 18;

ORDER BY used to Sort rows
SELECT * FROM students ORDER BY age DESC;

INSERT	to Add new data	
INSERT INTO students (name, age) VALUES ('Alex', 21);

UPDATE	to Change data	
UPDATE students SET age = 22 WHERE name = 'Alex';

ALTER TABLE Change table structure (add/remove/modify columns).
ALTER TABLE students ADD COLUMN email VARCHAR(50);

DELETE	to Remove data	
DELETE FROM students WHERE name = 'Alex';

TRUNCATE TABLE Remove all rows, but keep the table structure.
TRUNCATE TABLE students;

DROP TABLE Delete a table completely (structure + data).
DROP TABLE students;




//focusing mainly upon

READ — (SELECT)
Filter & Sort — (WHERE, ORDER BY)
GROUP & Summarize — (GROUP BY, HAVING)
Combine Data — (JOIN)



KEYS IN SQL:

1. Primary Key: A column (or set of columns) that uniquely identifies each row in a table / Must be unique — no duplicates allowed / Cannot be NULL — every row must have a value.

2. Candidate Key: Any column (or combo of columns) that could be a primary key because it uniquely identifies rows.
(we can have multiple c.k. but ony one as p.k.)

3. Alternate Key: A candidate key that was not chosen as the primary key.

4. Foreign Key: A column that creates a link/relationship between two tables.
(f.k. in one table refers to the p.k. in another table)

5. Composite Key: A primary key made of two or more columns.(sometime a single col can't be unique but a combination can)

6. Super Key: Any combination of columns that can uniquely identify rows.

**/





-- Basic example
/**
-- #Selecting all from table customers
SELECT * from customers;

-- #selecting only customername, country column from table customers
SELECT customername, country from customers


-- #or operator 
-- #selecting only those customername , country column where country is either France or Germany or USA 
SELECT customername, country from customers where country = "France" or country ="Germany" or country="USA";


-- #in operator (membership oerator)
-- #selecting only those customername, country where country is from the given list ("USA","Germany","France")
SELECT customername, country from customers where country in ("USA","Germany","France")


-- #and operator 
-- # selecting all column from customer table where country is USA and creditlimit is 0
select * from customers
select * from customers where country="USA" and creditlimit=0 


-- #between operator 
-- #selecting customername, country, creditlimit from table cutomers where creditlimit is b/w 20000 and 100000
-- #customers with creditLimit more than 20000 and less than 100000
select customername, country, creditlimit from customers where creditlimit between 20000 and 100000

  
select * from orders
where orderdate between "2003-02-01" and "2003-02-28"

-- another way
-- #month in order date must be 2nd and year must be 2003
select * from orders where month(orderdate)=2 and year(orderdate)=2003


-- #not operator
-- #slecting all column from orders where status is not shipped 
SELECT * from orders where status <> "Shipped"

--another way
-- SELECT * from orders where not status = "Shipped"

--another way
-- SELECT * from orders where status!= "Shipped"

-- #count operator 
-- #selecting count of ordernumber from orders
select count(ordernumber) from orders

-- #group by operator (when one is aggregated column and another is non aggregated column)
-- #groups all the rows with same status before aggregation happens
-- #to count ordernumber based on status 
select status, count(ordernumber) from orders group by status

-- #to count customers by country
select country , count(customername) from customers group by country



-- #order by operator(sorts the final result in asc or desc)
select country , count(customername) from customers 
group by country order by country

-- #sort according to the count of customer number in desc
select country , count(customername) from customers 
group by country order by count(customernumber) descending order


-- #count customers by city of USA
select city,count(customernumber) from customers 
where country ="USA" 
group by city



-- #having clause( giving condition after grouping and aggregation)( because where can't be used after group by)
-- #count customer by country with customer count more than 5
select count(customername), country from customers 
group by country 
having count(Customername)>5

**/





--creating a new database SchoolDB

create database SchoolDB;  
use SchoolDB --using this database

--creating a table students with following datatypes
Create table students(       
    student_id int Primary key,
    first_name varchar(50),
    last_name varchar(50),
    age int,
    dob date,
    marks float
);
-- show tables;   --show all tables inside the database
-- describe students;   -- show the structure of table

/**
+-------------+--------------+------+-----+---------+-------+
| Field       | Type         | Null | Key | Default | Extra |
+-------------+--------------+------+-----+---------+-------+
| student_id  | int          | NO   | PRI | NULL    |       |
| first_name  | varchar(50)  | YES  |     | NULL    |       |
| last_name   | varchar(50)  | YES  |     | NULL    |       |
| age         | int          | YES  |     | NULL    |       |
| dob         | date         | YES  |     | NULL    |       |
| marks       | float        | YES  |     | NULL    |       |
+-------------+--------------+------+-----+---------+-------+
**/


--inserting values inside the table students
insert into students( student_id ,first_name, last_name, age, dob, marks) values(1,"Hermione","Granger",16, "2007-09-02",98.88);

--another way for inserting values
insert into students values
(2,"Harry","Potter",16, "2007-03-11",87.98),
(3,"Ronald","Weasley",16, "2007-05-19",85.78),
(4, "Draco", "Malfoy", 16, "2007-06-05", 70.55),
(5, "Luna", "Lovegood", 15, "2008-02-13", 88.45),
(6, "Neville", "Longbottom", 16, "2007-07-30", 75.35),
(7, "Ginny", "Weasley", 15, "2008-08-11", 85.20),
(8, "Fred", "Weasley", 17, "2006-04-01", 80.00),
(9, "George", "Weasley", 17, "2006-04-01", 80.00),
(10, "Cho", "Chang", 16, "2007-10-01", 82.50);


 
-- select * from students


--students with marks b/w 80 and 90
select * from students where marks between 80 and 90


--Count how many students belongs to 'Weasley' family
select count(student_id) from students where last_name="Weasley";

--weasley family members sorted by marks
 select * from students where last_name="Weasley" order by marks desc;

--Students born after 2007-01-01
select * from students where dob > "2007-01-01";


--updating harry's marks to 90
update students set marks=90 where first_name="Harry";
select * from students;


--delete fred's record (he's no more the student of hogwarts)
delete from students where first_name="Fred";
select * from students;




-- output table:
/**
+------------+------------+------------+-----+------------+-------+
| student_id | first_name | last_name  | age | dob        | marks |
+------------+------------+------------+-----+------------+-------+
| 1          | Hermione   | Granger    | 16  | 2007-09-02 | 98.88 |
| 2          | Harry      | Potter     | 16  | 2007-03-11 | 95.00 |
| 3          | Ronald     | Weasley    | 16  | 2007-05-19 | 77.78 |
| 4          | Draco      | Malfoy     | 16  | 2007-06-05 | 70.55 |
| 5          | Luna       | Lovegood   | 15  | 2008-02-13 | 88.45 |
| 6          | Neville    | Longbottom | 16  | 2007-07-30 | 75.35 |
| 7          | Ginny      | Weasley    | 15  | 2008-08-11 | 85.20 |
| 9          | George     | Weasley    | 17  | 2006-04-01 | 80.00 |
| 10         | Cho        | Chang      | 16  | 2007-10-01 | 82.50 |
+------------+------------+------------+-----+------------+-------+

**/

