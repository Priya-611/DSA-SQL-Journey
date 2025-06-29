-- Aggregate Function: do calculations on multiple rows and return a single value.
-- Function 	What it does	              Example
-- COUNT()  	Counts rows	                How many customers?
-- SUM()	    Adds up numeric values	    Total sales amount
-- AVG()      Calculates average	        Average marks
-- MIN()	    Smallest value	            Oldest DOB
-- MAX()	    Largest value	              Highest marks



-- COUNT(*) = counts all rows
-- COUNT(column) = counts non-NULL values


-- Aggregate + GROUP BY gives summary per group.
-- WHERE filters rows before grouping
-- HAVING filters groups after aggregation




-- #Customers table 
select * from customers

-- #count total number of customers
select count(*) from customers


-- #country with highest no of orders
select  country, count(customername) from customers
group by country order by count(country) desc;



-- #find the average credit limit from customers table
select avg(creditlimit) from customers


-- We can't you use an aggregate function with a comparison operator directly without group by or subquery
-- Aggregate functions (MAX(), MIN(), SUM(), AVG(), COUNT()) operate over sets of rows.
-- Comparison operators (=, >, <, >=, <=) operate on scalar (single) values per row.


-- #find customers with credit limit less than the average
select * from customers where creditlimit <(select avg(creditlimit) from customers)


-- #cutsomers with very less creditlimit
select customername, creditlimit from customers where creditlimit between 0 and 20000

-- #count the customers from germany with 0 creditlimit 
select country,count(customername) from customers where country ="Germany" or country="USA" and creditlimit=0
group by country;




-- #Orders table 

-- count total no. of orders
select count(*) from orders


-- select every column from orders where order date is latest
select * from orders where orderdate =(select max(orderdate)  from orders)


select * from orders
-- find the most recent order date
select max(orderdate) as Latest_date from orders


  
-- #HAVING 
-- SELECT column, AGG_FUNC(column2) FROM table GROUP BY column HAVING condition_on_group;


-- country with more than 5 customers
select country , count(*) from customers 
group by country having count(*) >5;



--  group orders by status with less than 10 orders
select status,count(*) from orders
group by status having count(*) <10;

-- find average creditlmit of each country and filter by average limit more than 80K
select country,avg(creditlimit) as average_creditlimit from customers
group by country
having avg(creditlimit) >80000


-- Find customers from USA with more than 2 orders
select customernumber,count(*) from orders where customernumber in ( 
    select customernumber from customers where country="USA"
)
group by customernumber having count(*)>2;




-- #TCL COMMANDS

-- BEGIN = start transaction
-- COMMIT = save changes
-- ROLLBACK = undo all changes since BEGIN

select * from customers;
BEGIN;

update customers set phone = 1111 where customerlastname="King";
delete from cutomers where city="Las Vegas"

commit;
select * from customers;

rollback;

select * from customers



-- SAVEPOINT = temporary bookmark
-- ROLLBACK TO SAVEPOINT = undo up to that point
-- COMMIT = finish


Begin;
update orders set orderdate = "2025-06-23" where status="In Process";
Savepoint pt1;
delete from orders where status ="Disputed";
rollback to pt1;  
-- only update stays and delete is removed

commit;






-- Date Functions:
-- Function     	Purpose	                            Example
-- NOW()	        Current date and time              	SELECT NOW(); → 2025-06-21 12:34:56
-- CURDATE()   	Current date only	                SELECT CURDATE(); → 2025-06-21
-- CURTIME()	    Current time only	                SELECT CURTIME(); → 12:34:56
-- DATE()	        Extract date from datetime	        SELECT DATE(NOW());
-- YEAR()      	Extract year	                    SELECT YEAR('2024-05-01'); → 2024
-- MONTH()	        Extract month number	            SELECT MONTH('2024-05-01'); → 5
-- DAY()       	Extract day of month	            SELECT DAY('2024-05-01'); → 1
-- DAYNAME()	    Day name	                        SELECT DAYNAME('2024-05-01'); → Wednesday
-- MONTHNAME()	    Month name                      	SELECT MONTHNAME('2024-05-01'); → May
-- DATEDIFF()	    Difference in days                 	SELECT DATEDIFF('2025-06-30', '2025-06-21'); → 9
-- DATE_ADD()	    Add interval	                    SELECT DATE_ADD('2025-06-21', INTERVAL 7 DAY);
-- DATE_SUB()	    Subtract interval               	SELECT DATE_SUB('2025-06-21', INTERVAL 1 MONTH);
-- LAST_DAY()	    Last day of month	                SELECT LAST_DAY('2025-06-21'); → 2025-06-30
-- EXTRACT()	    Extract parts                   	SELECT EXTRACT(WEEK FROM '2025-06-21');




select * from orders
select now()
select day(now())

-- select orders from march 2005
select * from orders where year(orderdate) = 2005 and month(orderdate) = 3

-- find difference in days between orderdate and shippeddate
select ordernumber,orderdate,datediff(shippeddate,orderdate,day) from orders;

-- ordernumber 10111 is delayed
select orderdate,DATE_ADD(requiredate,INTERVAL 7 DAY ) from orders where ordernumber=10111;


-- selecting month and day of orderdate
SELECT ordernumber, orderdate , month(orderdate),day(orderdate) from orders;
SELECT ordernumber, orderdate , monthname(orderdate), dayname(orderdate) from orders;



-- EXTRACT(part FROM date)
-- part ->	What you want to extract (like YEAR, MONTH, DAY, HOUR, WEEK, QUARTER)
-- date ->	The date or timestamp column
SELECT orderdate, extract(year from orderdate),extract(month from orderdate) from orders;



-- TO_DATE  -> conversion function
-- it converts a string (text) into a proper DATE using a specified format pattern.
-- TO_DATE(string, format)

SELECT TO_DATE('21-06-2025', 'DD-MM-YYYY');






