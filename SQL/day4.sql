-- #CASE: SQL’s version of if-else or switch
-- can be used to:
-- Categorize values
-- Replace values with labels
-- Write conditional calculations
-- Add logic in SELECT, ORDER BY, GROUP BY, and even WHERE



-- CASE
--   WHEN condition1 THEN result1
--   WHEN condition2 THEN result2
--   ELSE default_result
-- END


-- If condition1 is true → return result1
-- Else if condition2 is true → return result2
-- Else → return the ELSE result




-- we can use case in: 
-- ✔️ SELECT → show different output for each row
-- ✔️ ORDER BY → sort differently for different conditions
-- ✔️ WHERE → rare, just use conditions directly! (less common, but works)
-- ✔️ GROUP BY → indirectly by creating a new label



-- 1. CASE in SELECT
SELECT ordernumber, orderdate, requireddate, shippeddate,
    CASE
        when shippeddate > requireddate then 'Late'
        else 'on time'
    END as shipping_status 
from orders;

-- (it creates a new column named as shipping status and fill it with the value given on the basis of condition provided)



-- 2. CASE in ORDER BY
SELECT customername, creditlimit,
    CASE
        When creditlimit >= 100000 then 'Premium'
        When creditlimit >= 50000 then 'Gold'
        else 'Standard'
    END as category
from customers
order BY
    CASE
        When creditlimit >= 100000 then 1
        When creditlimit >= 50000 then 2
        else 3
    end;
-- (Sort customers by category — Premium first, Gold second, Standard last.)
-- (create a category column following the applied condition and sort the creditlimit on that condition  )



-- 3. CASE in WHERE
SELECT ordernumber, orderdate, requireddate,shippeddate from orders
where 
 case
    when shippeddate> requireddate then TRUE
    else FALSE
end;

-- or use directly(where requireddate > shippeddate)
-- (will show only that data that follows the given condition)



-- 4. CASE in GROUP BY
SELECT 
    CASE
        When creditlimit >=100000 then 'Premium'
        when creditlimit >=50000 then 'Gold'
        else 'Standard'
    end as category,
    count(*) as toatl_cust,
    avg(creditlimit) as avg_credit
from customers
group by 
    CASE
        when creditlimit >= 100000 then 'Premium'
        when creditlimit >= 50000 then 'Gold'
        else 'Standard'
    end;

-- (group customers into Premium, Gold & Standard and then count them and find avg of creditlimit)
-- we don't have a category column , so firstly we'll create that using CASE
-- then  we'll appply aggregate function per group 
-- and to apply aggregate we need to group them
-- group customers into:
-- -->Premium (credit limit ≥ 100,000)
-- -->Gold (credit limit ≥ 50,000)
-- -->Standard (credit limit < 50,000)





-- Revisiting SUBQUERIES more deeply and properly this time
-- a query inside another query.

-- TYPES of SUBQUERY:

-- I. based on WHAT they RETURN

-- 1. Scalar Subquery: Returns a single value        [(SELECT AVG(price) FROM products)]
select * from customers where creditlimit > (SELECT avg(creditlimit) from customers);



-- 2. Row Subquery: Returns exactly one row (but can have multiple columns)   [ (SELECT name, age FROM employees WHERE id = 5)]
SELECT customername,city, state from customers where creditlimit = (SELECT max(creditlimit) from customers);


-- 3. Table Subquery: Returns multiple rows & columns (a whole result set)      [ FROM (SELECT * FROM orders.....)]
SELECT category, count(*) FROM (
    SELECT customername,
        CASE
            WHEN creditlimit >= 100000 then "Premium"
            WHEN creditlimit >= 50000 then "Gold"
            ELSE "Standard"
        END AS category
    from customers
) as temp
group by category;


-- this subquery produces a temporary table with:
-- customerName  	category
-- Alice	        Premium
-- Bob	            Gold
-- Charlie	        Standard
--temporary result is aliased as temp.

-- outer subquery groups all rows by category
-- For each group, it counts how many rows/customers are in that group.



-- 4. Correlated Subquery:	Returns value(s) per row of outer query   	[WHERE salary > (...)] 
SELECT customername , country, creditlimit from customers as c1 where creditlimit > ( select avg(creditlimit) from customers as c2 where c1.country=c2.country);
-- (c1 the main row you’re checking
-- c2	all rows in customers for calculating the average)   [What is the average credit limit for this customer’s country?]

-- [For the customer in c1 (outer), find rows in c2 (inner) with the same country.]


-- ┌────────────┐         ┌───────────────┐
-- | customers        |         | customers      |
-- |   (c1)           |         |   (c2)         |
-- └────────────┘         └───────────────┘
--       │                    │
--       │ c1.country = c2.country 
--       └─────────────▶ AVG(creditLimit)




-- II. Based on WHERE they appear
-- Type	                    Where it appears
-- In SELECT	                As a calculated column
-- In FROM	                    Acts like a temporary table (inline view)
-- In WHERE or HAVING	        Used to filter
-- In EXISTS or IN	            Used to check existence




-- III. By Execution
-- Type	                            How it runs
-- Non-Correlated Subquery         	Runs once → static value for outer query
-- Correlated Subquery	            Runs once per row → depends on outer query’s current row




-- Some Examples:
-- find customers with more than avg creditlimit
Select customername, creditlimit from customers where creditlimit > (select avg(creditlimit) from customers);

  
--find avg credit limit and show it with each customer name i.e. the overall average credit limit (same for each row)
select customername, creditlimit, (Select avg(creditlimit) from customers) as avg_credit from customers;


-- Find countries whose total customer credit limit is higher than the overall average credit limit.
--(group customers by country and find sum of creditlimit for each countyr ,, show only those data whose sum is > avg)
select country, sum(creditlimit) from customers 
group by country 
having sum(creditlimit) > (select avg(creditlimit) from customers);


-- Find customers who have at least one order.
select customername, customernumber from customers as c where exists(
    select 1 from orders as o where o.customernumber= c.customernumber;
);
-- EXISTS is a logical operator used in WHERE or HAVING clauses.
-- if the subquery returns at least one row, EXISTS is TRUE; if it returns zero rows, it’s FALSE.


-- Find orders placed by customers from Germany.
Select * from orders where customernumber in (SELECT customernumber from customers where country = "Germany");

  
-- Increase credit limit by 10% for all customers whose credit limit is below the average.
update customers set creditlimit = creditlimit*1.1 where creditlimit < (Select avg(creditlimit) from customers);


-- Get the top 5 biggest credit limits
select creditlimit  from ( select creditlimit from customers order by creditlimit desc LIMIT 5) as top5;

/**
-- LIMIT is used to restrict the number of rows returned by a query.
-- Sometimes, you want to skip some rows and get the next set — useful for pages.

SELECT * 
FROM customers
LIMIT 5 OFFSET 10;    --Skips the first 10 rows and returns the next 5.
**/


