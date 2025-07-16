-- 3436. Find Valid Emails
-- Input:
-- Users table:
-- +---------+---------------------+
-- | user_id | email               |
-- +---------+---------------------+
-- | 1       | alice@example.com   |
-- | 2       | bob_at_example.com  |
-- | 3       | charlie@example.net |
-- | 4       | david@domain.com    |
-- | 5       | eve@invalid         |
-- +---------+---------------------+
-- Output:

-- +---------+-------------------+
-- | user_id | email             |
-- +---------+-------------------+
-- | 1       | alice@example.com |
-- | 4       | david@domain.com  |
-- +---------+-------------------+

select user_id,email from Users where email regexp '^[A-Za-z0-9]+@+[A-Za-z]+\\.com$';






--Some More Topics:
/*
1. Advanced Joins:
-> Self Join – when a table is joined with itself.
-> Full Outer Join – returns all rows from both tables (some platforms like LeetCode don’t have it, but it’s important in real life).
-> Cross Join – Cartesian product (use carefully).


2. Window Functions:
 A window function performs calculations across a set of rows that are related to the current row.
 Access previous or next row’s data without a self join.
 Great for comparisons (e.g., find days since last login).

<window_function>() OVER ( PARTITION BY <columns> ORDER BY <columns>)
["For each row, look at this group of rows (partition) in this order (order by) and then apply the function.”]

-- OVER defines the window of rows the function should look at.
-- PARTITION BY It divides your data into groups (like a virtual GROUP BY) but does not collapse rows [Each class gets its own ranking.]

-> ROW_NUMBER() - Gives a unique sequential number to each row in the order you specify. Even if two rows have the same values, they still get different numbers.
-> RANK() - Gives a ranking with gaps when there are ties. If two rows share the same value, they get the same rank, 'but the next rank is skipped'.
-> DENSE_RANK() - Similar to RANK(), but no gaps in ranking after ties.
-> LAG(column, n) – get previous row’s value. [Look n rows before the current row and return that val]
-> LEAD(column, n) – get next row’s value. [Look n rows after the current row.]
-> SUM() / AVG() OVER() - Running totals or averages without grouping rows.
-> FIRST_VALUE() / LAST_VALUE() – get first or last value in a partition.
-> NTILE(n) – split rows into n buckets.  [to divide all rows in n no. of partition] [each row will get it's own class no.]

      SELECT player_id, event_date, LAG(event_date,1) OVER (PARTITION BY player_id ORDER BY event_date) AS previous_date FROM Activity;
      SELECT order_id, amount, LEAD(amount,1) OVER (ORDER BY order_id) AS next_amount FROM Orders;
      SELECT student_id, class, score, RANK() OVER (PARTITION BY class ORDER BY score DESC) AS rank_in_class FROM Students;



 3. GROUPING SETS / ROLLUP / CUBE
These are more advanced aggregations:
-> ROLLUP gives subtotals and grand totals.  [ First, groups by (region, product). Then subtotal for each region. Then grand total ]

    SELECT region, product, SUM(sales) AS total_sales
    FROM Sales
    GROUP BY ROLLUP(region, product);

-> CUBE gives all possible combinations. [Groups by (region, product). Groups by (region) only. Groups by (product) only. Groups by () (grand total)]

    SELECT region, product, SUM(sales) AS total_sales
    FROM Sales
    GROUP BY CUBE(region, product);

-> GROUPING SETS - allows you to get multiple groupings in a single query. It’s like running several GROUP BY queries and combining their results with UNION ALL, but you can write it once.

    SELECT columns, aggregate_functions
    FROM table
    GROUP BY GROUPING SETS (
        (col1, col2),   -- first grouping
        (col1),         -- second grouping
        ()              -- grand total
    );


*/


