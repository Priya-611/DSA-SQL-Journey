-- 585. Investments in 2016
--   Insurance table:
-- +-----+----------+----------+-----+-----+
-- | pid | tiv_2015 | tiv_2016 | lat | lon |
-- +-----+----------+----------+-----+-----+
-- | 1   | 10       | 5        | 10  | 10  |
-- | 2   | 20       | 20       | 20  | 20  |
-- | 3   | 10       | 30       | 20  | 20  |
-- | 4   | 10       | 40       | 40  | 40  |
-- +-----+----------+----------+-----+-----+
-- Output: 
-- +----------+
-- | tiv_2016 |
-- +----------+
-- | 45.00    |
-- +----------+
-- (add tiv_2016 where tiv_2015 is same i.e it's count>1 and lat ,lon are equal i.e count=1)

select round(sum(tiv_2016),2) as tiv_2016 from Insurance 
where tiv_2015 in(select tiv_2015 from Insurance group by tiv_2015 having count(*)>1) 
and (lat,lon) in (select lat,lon from Insurance group by lat,lon having count(*)=1);




-- WITH clause
/*
The WITH clause (also known as Common Table Expressions, or CTEs).
It lets you build temporary result sets that make your queries easier to read, write, and manage.
WITH lets you create a temporary table (like a shortcut) that you can use in your main query.
  

WITH cte_name AS (
    SELECT ...
)
SELECT ...
FROM cte_name;
*/

-- Without WITH:

SELECT product, SUM(amount) 
FROM Sales 
GROUP BY product;

-- With WITH:

WITH total_sales AS (
  SELECT product, SUM(amount) AS total
  FROM Sales
  GROUP BY product
)
SELECT * FROM total_sales;

-- Both give the same result. But with WITH, you can re-use or join the total_sales CTE later, making things clean!




-- Q1: Filter Employees With Above Average Salary
-- | id | name | salary |
-- | -- | ---- | ------ |
-- | 1  | A    | 50000  |
-- | 2  | B    | 60000  |
-- | 3  | C    | 40000  |

with New_table as(
select avg(salary) as avg_sal from Employees
)
select * from Employee where salary > (select avg_sal from New_table);





-- Q2:  Count Orders in Last 30 Days
with New_table as(
  select * from orders where order_date >= curdate() - interval 30 day
)
select count(*) as count_orders from New_table;




-- Q3: Find Customers Who Ordered More Than Once

with order_counts(
  select customer_id,count(*) as total_order from orders group by customer_id
  )
select customer_id from order_counts where total_order> 1;




-- Q4: List Products With No Sales
with new_table as(
  select distinct product_id from Sales
  )
select product_name from Product where product_id not in(select product_id from new_table);

