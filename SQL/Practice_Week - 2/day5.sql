-- 1587. Bank Account Summary II
--   Input: 
-- Users table:
-- +------------+--------------+
-- | account    | name         |
-- +------------+--------------+
-- | 900001     | Alice        |
-- | 900002     | Bob          |
-- | 900003     | Charlie      |
-- +------------+--------------+
-- Transactions table:
-- +------------+------------+------------+---------------+
-- | trans_id   | account    | amount     | transacted_on |
-- +------------+------------+------------+---------------+
-- | 1          | 900001     | 7000       |  2020-08-01   |
-- | 2          | 900001     | 7000       |  2020-09-01   |
-- | 3          | 900001     | -3000      |  2020-09-02   |
-- | 4          | 900002     | 1000       |  2020-09-12   |
-- | 5          | 900003     | 6000       |  2020-08-07   |
-- | 6          | 900003     | 6000       |  2020-09-07   |
-- | 7          | 900003     | -4000      |  2020-09-11   |
-- +------------+------------+------------+---------------+
-- Output: 
-- +------------+------------+
-- | name       | balance    |
-- +------------+------------+
-- | Alice      | 11000      |
-- +------------+------------+
-- Explanation: 
-- Alice's balance is (7000 + 7000 - 3000) = 11000.
-- Bob's balance is 1000.
-- Charlie's balance is (6000 + 6000 - 4000) = 8000.

select u.name ,sum(t.amount) as balance from Users u join Transactions t on u.account=t.account
group by t.account having balance >10000;





-- 1741. Find Total Time Spent by Each Employee
--   Input: 
-- Employees table:
-- +--------+------------+---------+----------+
-- | emp_id | event_day  | in_time | out_time |
-- +--------+------------+---------+----------+
-- | 1      | 2020-11-28 | 4       | 32       |
-- | 1      | 2020-11-28 | 55      | 200      |
-- | 1      | 2020-12-03 | 1       | 42       |
-- | 2      | 2020-11-28 | 3       | 33       |
-- | 2      | 2020-12-09 | 47      | 74       |
-- +--------+------------+---------+----------+
-- Output: 
-- +------------+--------+------------+
-- | day        | emp_id | total_time |
-- +------------+--------+------------+
-- | 2020-11-28 | 1      | 173        |
-- | 2020-11-28 | 2      | 30         |
-- | 2020-12-03 | 1      | 41         |
-- | 2020-12-09 | 2      | 27         |
-- +------------+--------+------------+
-- Explanation: 
-- Employee 1 has three events: two on day 2020-11-28 with a total of (32 - 4) + (200 - 55) = 173, and one on day 2020-12-03 with a total of (42 - 1) = 41.
-- Employee 2 has two events: one on day 2020-11-28 with a total of (33 - 3) = 30, and one on day 2020-12-09 with a total of (74 - 47) = 27.
select event_day as day ,emp_id,sum(out_time -in_time)total_time from Employees 
group by emp_id,event_day;









-- 1795. Rearrange Products Table
--   Input: 
-- Products table:
-- +------------+--------+--------+--------+
-- | product_id | store1 | store2 | store3 |
-- +------------+--------+--------+--------+
-- | 0          | 95     | 100    | 105    |
-- | 1          | 70     | null   | 80     |
-- +------------+--------+--------+--------+
-- Output: 
-- +------------+--------+-------+
-- | product_id | store  | price |
-- +------------+--------+-------+
-- | 0          | store1 | 95    |
-- | 0          | store2 | 100   |
-- | 0          | store3 | 105   |
-- | 1          | store1 | 70    |
-- | 1          | store3 | 80    |
-- +------------+--------+-------+
--something new 
select product_id,'store1' as store ,store1 as price from Products where store1 is not null
union
select product_id,'store2' as store ,store2 as price from Products where store2 is not null
union
select product_id,'store3' as store ,store3 as price from Products where store3 is not null






-- 1873. Calculate Special Bonus
--   Input: 
-- Employees table:
-- +-------------+---------+--------+
-- | employee_id | name    | salary |
-- +-------------+---------+--------+
-- | 2           | Meir    | 3000   |
-- | 3           | Michael | 3800   |
-- | 7           | Addilyn | 7400   |
-- | 8           | Juan    | 6100   |
-- | 9           | Kannon  | 7700   |
-- +-------------+---------+--------+
-- Output: 
-- +-------------+-------+
-- | employee_id | bonus |
-- +-------------+-------+
-- | 2           | 0     |
-- | 3           | 0     |
-- | 7           | 7400  |
-- | 8           | 0     |
-- | 9           | 7700  |
-- +-------------+-------+
select employee_id,(case when employee_id%2!=0 and name not like 'M%' then salary else 0 end) as bonus from Employees order by employee_id;





-- 1965. Employees With Missing Information
-- Input: 
-- Employees table:
-- +-------------+----------+
-- | employee_id | name     |
-- +-------------+----------+
-- | 2           | Crew     |
-- | 4           | Haven    |
-- | 5           | Kristian |
-- +-------------+----------+
-- Salaries table:
-- +-------------+--------+
-- | employee_id | salary |
-- +-------------+--------+
-- | 5           | 76071  |
-- | 1           | 22517  |
-- | 4           | 63539  |
-- +-------------+--------+
-- Output: 
-- +-------------+
-- | employee_id |
-- +-------------+
-- | 1           |
-- | 2           |
-- +-------------+
-- Explanation: 
-- Employees 1, 2, 4, and 5 are working at this company.
-- The name of employee 1 is missing.
-- The salary of employee 2 is missing.

select employee_id from Employees where name is null 
union
select employee_id from Salaries where salary is null
union 
select employee_id from Employees where employee_id not in(select employee_id from Salaries)
union
select employee_id from Salaries where employee_id not in(select employee_id from Employees )
order by employee_id;







-- 1158. Market Analysis I
--   Input: 
-- Users table:
-- +---------+------------+----------------+
-- | user_id | join_date  | favorite_brand |
-- +---------+------------+----------------+
-- | 1       | 2018-01-01 | Lenovo         |
-- | 2       | 2018-02-09 | Samsung        |
-- | 3       | 2018-01-19 | LG             |
-- | 4       | 2018-05-21 | HP             |
-- +---------+------------+----------------+
-- Orders table:
-- +----------+------------+---------+----------+-----------+
-- | order_id | order_date | item_id | buyer_id | seller_id |
-- +----------+------------+---------+----------+-----------+
-- | 1        | 2019-08-01 | 4       | 1        | 2         |
-- | 2        | 2018-08-02 | 2       | 1        | 3         |
-- | 3        | 2019-08-03 | 3       | 2        | 3         |
-- | 4        | 2018-08-04 | 1       | 4        | 2         |
-- | 5        | 2018-08-04 | 1       | 3        | 4         |
-- | 6        | 2019-08-05 | 2       | 2        | 4         |
-- +----------+------------+---------+----------+-----------+
-- Items table:
-- +---------+------------+
-- | item_id | item_brand |
-- +---------+------------+
-- | 1       | Samsung    |
-- | 2       | Lenovo     |
-- | 3       | LG         |
-- | 4       | HP         |
-- +---------+------------+
-- Output: 
-- +-----------+------------+----------------+
-- | buyer_id  | join_date  | orders_in_2019 |
-- +-----------+------------+----------------+
-- | 1         | 2018-01-01 | 1              |
-- | 2         | 2018-02-09 | 2              |
-- | 3         | 2018-01-19 | 0              |
-- | 4         | 2018-05-21 | 0              |
-- +-----------+------------+----------------+

select u.user_id as buyer_id, u.join_date,count(o.order_date)as orders_in_2019 from Users u
  left join Orders o 
  on u.user_id=o.buyer_id and year(o.order_date)='2019' 
  group by u.user_id ,u.join_date;
/*
why can't we use where clause instead od and here-->
Problem with WHERE clause in this case:
 This turns the LEFT JOIN into an INNER JOIN!
Because WHERE YEAR(o.order_date) = 2019 will remove any rows where o.order_date is NULL — which happens for users who didn't place any order at all.
So users with zero orders will be excluded from the final result.
*/

