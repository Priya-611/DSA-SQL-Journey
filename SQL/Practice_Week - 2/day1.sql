-- 1164. Product Price at a Given Date
-- Input: 
-- Products table:
-- +------------+-----------+-------------+
-- | product_id | new_price | change_date |
-- +------------+-----------+-------------+
-- | 1          | 20        | 2019-08-14  |
-- | 2          | 50        | 2019-08-14  |
-- | 1          | 30        | 2019-08-15  |
-- | 1          | 35        | 2019-08-16  |
-- | 2          | 65        | 2019-08-17  |
-- | 3          | 20        | 2019-08-18  |
-- +------------+-----------+-------------+
-- Output: 
-- +------------+-------+
-- | product_id | price |
-- +------------+-------+
-- | 2          | 50    |
-- | 1          | 35    |
-- | 3          | 10    |
-- +------------+-------+
-- (show the price of every product as of 2019-08-16.If there's no price change on or before that date, default to price = 10.)

-- firtsly set default price for products with no price change on/before the date
-- Most recent price on or before 2019-08-16
select distinct product_id ,10 as price from Products where product_id not in
(select product_id from Products where change_date<='2019-08-16')
union
select product_id, new_price as price from Products where (product_id, change_date) in
(select product_id,max(change_date) from Products where change_date<='2019-08-16'
group by product_id)
order by product_id;

/*UNION – Combine both
UNION merges:
Products with actual prices.
Products with default price 10.
Automatically removes duplicates.*/








-- 1179. Reformat Department Table
-- Input: 
-- Department table:
-- +------+---------+-------+
-- | id   | revenue | month |
-- +------+---------+-------+
-- | 1    | 8000    | Jan   |
-- | 2    | 9000    | Jan   |
-- | 3    | 10000   | Feb   |
-- | 1    | 7000    | Feb   |
-- | 1    | 6000    | Mar   |
-- +------+---------+-------+
-- Output: 
-- +------+-------------+-------------+-------------+-----+-------------+
-- | id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
-- +------+-------------+-------------+-------------+-----+-------------+
-- | 1    | 8000        | 7000        | 6000        | ... | null        |
-- | 2    | 9000        | null        | null        | ... | null        |
-- | 3    | null        | 10000       | null        | ... | null        |
-- +------+-------------+-------------+-------------+-----+-------------+
-- Explanation: The revenue from Apr to Dec is null.
-- Note that the result table has 13 columns (1 for the department id + 12 for the months).

select id, 
sum(case when month='Jan' then revenue else null end) as Jan_Revenue,
sum(case when month='Feb' then revenue else null end) as Feb_Revenue,
sum(case when month='Mar' then revenue else null end) as Mar_Revenue,
sum(case when month='Apr' then revenue else null end) as Apr_Revenue,
sum(case when month='May' then revenue else null end) as May_Revenue,
sum(case when month='Jun' then revenue else null end) as Jun_Revenue,
sum(case when month='Jul' then revenue else null end) as Jul_Revenue,
sum(case when month='Aug' then revenue else null end) as Aug_Revenue,
sum(case when month='Sep' then revenue else null end) as Sep_Revenue,
sum(case when month='Oct' then revenue else null end) as Oct_Revenue,
sum(case when month='Nov' then revenue else null end) as Nov_Revenue,
sum(case when month='Dec' then revenue else null end) as Dec_Revenue from Department
group by id;








-- 175. Combine Two Tables
-- Input: 
-- Person table:
-- +----------+----------+-----------+
-- | personId | lastName | firstName |
-- +----------+----------+-----------+
-- | 1        | Wang     | Allen     |
-- | 2        | Alice    | Bob       |
-- +----------+----------+-----------+
-- Address table:
-- +-----------+----------+---------------+------------+
-- | addressId | personId | city          | state      |
-- +-----------+----------+---------------+------------+
-- | 1         | 2        | New York City | New York   |
-- | 2         | 3        | Leetcode      | California |
-- +-----------+----------+---------------+------------+
-- Output: 
-- +-----------+----------+---------------+----------+
-- | firstName | lastName | city          | state    |
-- +-----------+----------+---------------+----------+
-- | Allen     | Wang     | Null          | Null     |
-- | Bob       | Alice    | New York City | New York |
-- +-----------+----------+---------------+----------+

select p.firstName, p.lastName, a.city, a.state from Person p 
  left join Address a
on p.personId=a.personId ;







-- 177. Nth Highest Salary
--  Input: 
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- n = 2
-- Output: 
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set N=N-1;
  RETURN (
    select distinct salary from Employee order by salary desc limit 1 offset N
  );
END 
/*LIMIT Specifies how many rows to return.
OFFSET Skips a number of rows before starting to return rows.*/






-- 627. Swap Salary
--   Input: 
-- Salary table:
-- +----+------+-----+--------+
-- | id | name | sex | salary |
-- +----+------+-----+--------+
-- | 1  | A    | m   | 2500   |
-- | 2  | B    | f   | 1500   |
-- | 3  | C    | m   | 5500   |
-- | 4  | D    | f   | 500    |
-- +----+------+-----+--------+
-- Output: 
-- +----+------+-----+--------+
-- | id | name | sex | salary |
-- +----+------+-----+--------+
-- | 1  | A    | f   | 2500   |
-- | 2  | B    | m   | 1500   |
-- | 3  | C    | f   | 5500   |
-- | 4  | D    | m   | 500    |
-- +----+------+-----+--------+
update Salary set sex=
case 
    when sex='f' then 'm'
    when sex='m' then 'f' 
end;






-- 178. Rank Scores
-- Input: 
-- Scores table:
-- +----+-------+
-- | id | score |
-- +----+-------+
-- | 1  | 3.50  |
-- | 2  | 3.65  |
-- | 3  | 4.00  |
-- | 4  | 3.85  |
-- | 5  | 4.00  |
-- | 6  | 3.65  |
-- +----+-------+
-- Output: 
-- +-------+------+
-- | score | rank |
-- +-------+------+
-- | 4.00  | 1    |
-- | 4.00  | 1    |
-- | 3.85  | 2    |
-- | 3.65  | 3    |
-- | 3.65  | 3    |
-- | 3.50  | 4    |
-- +-------+------+

select score,dense_rank() over(order by score desc) as 'rank' from Scores;
/*
ROW_NUMBER() -> Gives unique rank to each row, even if the values are the same.    [ROW_NUMBER() OVER (ORDER BY score DESC) AS row_num]
RANK() -> Gives same rank to tied scores, but skips the next rank(s).              [RANK() OVER (ORDER BY score DESC) AS `rank`]
DENSE_RANK() -> Gives same rank to tied scores, but does not skip the next rank.   [ DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`]
  
OVER() is used with window functions (like RANK(), ROW_NUMBER(), SUM(), etc.) to tell SQL how to process rows in relation to other rows.
*/



