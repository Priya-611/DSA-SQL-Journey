
-- 550. Game Play Analysis IV
--   Input: 
-- Activity table:
-- +-----------+-----------+------------+--------------+
-- | player_id | device_id | event_date | games_played |
-- +-----------+-----------+------------+--------------+
-- | 1         | 2         | 2016-03-01 | 5            |
-- | 1         | 2         | 2016-03-02 | 6            |
-- | 2         | 3         | 2017-06-25 | 1            |
-- | 3         | 1         | 2016-03-02 | 0            |
-- | 3         | 4         | 2018-07-03 | 5            |
-- +-----------+-----------+------------+--------------+
-- Output: 
-- +-----------+
-- | fraction  |
-- +-----------+
-- | 0.33      |
-- +-----------+
-- Explanation: 
-- Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33
select round(count(distinct a.player_id )/(select count(distinct player_id) from Activity),2) as fraction from Activity a join
(Select player_id, min(event_date) as first_login from Activity group by player_id) b
on a.player_id=b.player_id
where a.event_date = date_add(b.first_login, interval 1 day)


/* inner subquery-> b table  will have min(event_date) for each player
| player\_id | first\_login |
| ---------- | ------------ |
| 1          | 2016-03-01   |
| 2          | 2017-06-25   |
| 3          | 2016-03-02   |

join a and b
| a.player\_id | a.event\_date | b.first\_login |
| ------------ | ------------- | -------------- |
| 1            | 2016-03-01    | 2016-03-01     |
| 1            | 2016-03-02    | 2016-03-01     |
| 2            | 2017-06-25    | 2017-06-25     |
| 3            | 2016-03-02    | 2016-03-02     |
| 3            | 2018-07-03    | 2016-03-02     |

where condition -> keep only that player_id which if we add 1 day in first_login it will be same as event_date
| a.player\_id | a.event\_date | b.first\_login | Keep?                     |
| ------------ | ------------- | -------------- | ------------------------  |
| 1            | 2016-03-01    | 2016-03-01     | ❌   (not exactly 1 day) |
| 1            | 2016-03-02    | 2016-03-01     | ✅                       |
| 2            | 2017-06-25    | 2017-06-25     | ❌   (not exactly 1 day) |
| 3            | 2016-03-02    | 2016-03-02     | ❌   (not exactly 1 day) |
| 3            | 2018-07-03    | 2016-03-02     | ❌   (not exactly 1 day) |

count(a.player_id )  -> 1
select count(player_id)  ->3  (1,2,3)
*/





-- 1890. The Latest Login in 2020
--   Input: 
-- Logins table:
-- +---------+---------------------+
-- | user_id | time_stamp          |
-- +---------+---------------------+
-- | 6       | 2020-06-30 15:06:07 |
-- | 6       | 2021-04-21 14:06:06 |
-- | 6       | 2019-03-07 00:18:15 |
-- | 8       | 2020-02-01 05:10:53 |
-- | 8       | 2020-12-30 00:46:50 |
-- | 2       | 2020-01-16 02:49:50 |
-- | 2       | 2019-08-25 07:59:08 |
-- | 14      | 2019-07-14 09:00:00 |
-- | 14      | 2021-01-06 11:59:59 |
-- +---------+---------------------+
-- Output: 
-- +---------+---------------------+
-- | user_id | last_stamp          |
-- +---------+---------------------+
-- | 6       | 2020-06-30 15:06:07 |
-- | 8       | 2020-12-30 00:46:50 |
-- | 2       | 2020-01-16 02:49:50 |
-- +---------+---------------------+
-- Explanation: 
-- User 6 logged into their account 3 times but only once in 2020, so we include this login in the result table.
-- User 8 logged into their account 2 times in 2020, once in February and once in December. We include only the latest one (December) in the result table.
-- User 2 logged into their account 2 times but only once in 2020, so we include this login in the result table.
-- User 14 did not login in 2020, so we do not include them in the result table.

-- [select maximum time_stamp ]
select user_id,max(time_stamp) as last_stamp from Logins 
where year(time_stamp)=2020 
group by user_id;






-- 1393. Capital Gain/Loss
--   Input: 
-- Stocks table:
-- +---------------+-----------+---------------+--------+
-- | stock_name    | operation | operation_day | price  |
-- +---------------+-----------+---------------+--------+
-- | Leetcode      | Buy       | 1             | 1000   |
-- | Corona Masks  | Buy       | 2             | 10     |
-- | Leetcode      | Sell      | 5             | 9000   |
-- | Handbags      | Buy       | 17            | 30000  |
-- | Corona Masks  | Sell      | 3             | 1010   |
-- | Corona Masks  | Buy       | 4             | 1000   |
-- | Corona Masks  | Sell      | 5             | 500    |
-- | Corona Masks  | Buy       | 6             | 1000   |
-- | Handbags      | Sell      | 29            | 7000   |
-- | Corona Masks  | Sell      | 10            | 10000  |
-- +---------------+-----------+---------------+--------+
-- Output: 
-- +---------------+-------------------+
-- | stock_name    | capital_gain_loss |
-- +---------------+-------------------+
-- | Corona Masks  | 9500              |
-- | Leetcode      | 8000              |
-- | Handbags      | -23000            |
-- +---------------+-------------------+

-- (if operation is sell then add price and if operation is buy then subtract group by stock_name)
select stock_name, sum(
    case
    when operation='BUY' then -price
    when operation='SELL' then price
    end
 ) as capital_gain_loss from Stocks group by stock_name;







-- 3220. Odd and Even Transactions
--   Input:
-- transactions table:
-- +----------------+--------+------------------+
-- | transaction_id | amount | transaction_date |
-- +----------------+--------+------------------+
-- | 1              | 150    | 2024-07-01       |
-- | 2              | 200    | 2024-07-01       |
-- | 3              | 75     | 2024-07-01       |
-- | 4              | 300    | 2024-07-02       |
-- | 5              | 50     | 2024-07-02       |
-- | 6              | 120    | 2024-07-03       |
-- +----------------+--------+------------------+
  
-- Output:

-- +------------------+---------+----------+
-- | transaction_date | odd_sum | even_sum |
-- +------------------+---------+----------+
-- | 2024-07-01       | 75      | 350      |
-- | 2024-07-02       | 0       | 350      |
-- | 2024-07-03       | 0       | 120      |
-- +------------------+---------+----------+
  
select transaction_date, sum(case when amount%2!=0 then amount else 0 end) as odd_sum,
sum(case when amount%2=0 then amount else 0 end) as even_sum from transactions
group by transaction_date
order by transaction_date;

