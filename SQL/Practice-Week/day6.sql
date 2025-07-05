-- 1667. Fix Names in a Table
--   Input: 
-- Users table:
-- +---------+-------+
-- | user_id | name  |
-- +---------+-------+
-- | 1       | aLice |
-- | 2       | bOB   |
-- +---------+-------+

-- (sql has no function like proper , so we use upper with the first letter from left and lower rest of the letters)
select user_id,concat(
    upper(left(name,1)) , 
    lower(substr(name,2,length(name)))
    ) as name from Users
order by user_id;






-- 1484. Group Sold Products By The Date
-- Activities table:
-- +------------+------------+
-- | sell_date  | product     |
-- +------------+------------+
-- | 2020-05-30 | Headphone  |
-- | 2020-06-01 | Pencil     |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | Basketball |
-- | 2020-06-01 | Bible      |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | T-Shirt    |
-- +------------+------------+

-- Output:
-- +------------+----------+------------------------------+
-- | sell_date  | num_sold | products                     |
-- +------------+----------+------------------------------+
-- | 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
-- | 2020-06-01 | 2        | Bible,Pencil                 |
-- | 2020-06-02 | 1        | Mask                         |
-- +------------+----------+------------------------------+

-- (counting only distinct product & grouping all product seperated by comma ',')
select sell_date ,count( distinct product)as num_sold, group_concat(distinct product)as products from Activities
group by sell_date;







-- 1327. List the Products Ordered in a Period
-- Input: 
-- Products table:
-- +-------------+-----------------------+------------------+
-- | product_id  | product_name          | product_category |
-- +-------------+-----------------------+------------------+
-- | 1           | Leetcode Solutions    | Book             |
-- | 2           | Jewels of Stringology | Book             |
-- | 3           | HP                    | Laptop           |
-- | 4           | Lenovo                | Laptop           |
-- | 5           | Leetcode Kit          | T-shirt          |
-- +-------------+-----------------------+------------------+
-- Orders table:
-- +--------------+--------------+----------+
-- | product_id   | order_date   | unit     |
-- +--------------+--------------+----------+
-- | 1            | 2020-02-05   | 60       |
-- | 1            | 2020-02-10   | 70       |
-- | 2            | 2020-01-18   | 30       |
-- | 2            | 2020-02-11   | 80       |
-- | 3            | 2020-02-17   | 2        |
-- | 3            | 2020-02-24   | 3        |
-- | 4            | 2020-03-01   | 20       |
-- | 4            | 2020-03-04   | 30       |
-- | 4            | 2020-03-04   | 60       |
-- | 5            | 2020-02-25   | 50       |
-- | 5            | 2020-02-27   | 50       |
-- | 5            | 2020-03-01   | 50       |
-- +--------------+--------------+----------+
-- Output: 
-- +--------------------+---------+
-- | product_name       | unit    |
-- +--------------------+---------+
-- | Leetcode Solutions | 130     |
-- | Leetcode Kit       | 100     |
+--------------------+---------+

select p.product_name, sum(o.unit) as unit from Products p 
  join Orders o 
  on p.product_id=o.product_id
  where month(o.order_date) = 2 and year(o.order_date) =2020
  group by p.product_id, p.product_name
having sum(o.unit)>=100;







-- 1517. Find Users With Valid E-Mails
-- Input: 
-- Users table:
-- +---------+-----------+-------------------------+
-- | user_id | name      | mail                    |
-- +---------+-----------+-------------------------+
-- | 1       | Winston   | winston@leetcode.com    |
-- | 2       | Jonathan  | jonathanisgreat         |
-- | 3       | Annabelle | bella-@leetcode.com     |
-- | 4       | Sally     | sally.come@leetcode.com |
-- | 5       | Marwan    | quarz#2020@leetcode.com |
-- | 6       | David     | david69@gmail.com       |
-- | 7       | Shapiro   | .shapo@leetcode.com     |
-- +---------+-----------+-------------------------+

-- Write a solution to find the users who have valid emails.
-- A valid e-mail has a prefix name and a domain where:
-- The prefix name is a string that may contain letters (upper or lower case), digits, underscore '_', period '.', and/or dash '-'. The prefix name must start with a letter.
-- The domain is '@leetcode.com'.

select * from Users
WHERE REGEXP_LIKE(mail,'^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$','c');

/*REGEXP_LIKE filters rows where the email (mail) matches a pattern using regex.
'c' = case-sensitive matching
pattern for email:  '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$'

 `^`               | Start of string                                                            
 `[a-zA-Z]`        | First character is an **uppercase or lowercase letter**                    
 `[a-zA-Z0-9._-]*` | Zero or more of these: letter, digit, period `.`, underscore `_`, dash `-` 
 `@leetcode\\.com` | Must contain exactly `@leetcode.com` (escaped dot `\\.` means literal `.`) 
 `$`               | End of string                                                              
*/







-- 570. Managers with at Least 5 Direct Reports
-- Input: 
-- Employee table:
-- +-----+-------+------------+-----------+
-- | id  | name  | department | managerId |
-- +-----+-------+------------+-----------+
-- | 101 | John  | A          | null      |
-- | 102 | Dan   | A          | 101       |
-- | 103 | James | A          | 101       |
-- | 104 | Amy   | A          | 101       |
-- | 105 | Anne  | A          | 101       |
-- | 106 | Ron   | B          | 101       |
-- +-----+-------+------------+-----------+
-- Output: 
-- +------+
-- | name |
-- +------+
-- | John |
-- +------+

select e1.name from Employee e1 
  join Employee e2 
  on e1.id=e2.managerId
  group by e2.managerId
having count(e2.managerId)>=5;








-- 1934. Confirmation Rate
-- Input: 
-- Signups table:
-- +---------+---------------------+
-- | user_id | time_stamp          |
-- +---------+---------------------+
-- | 3       | 2020-03-21 10:16:13 |
-- | 7       | 2020-01-04 13:57:59 |
-- | 2       | 2020-07-29 23:09:44 |
-- | 6       | 2020-12-09 10:39:37 |
-- +---------+---------------------+
-- Confirmations table:
-- +---------+---------------------+-----------+
-- | user_id | time_stamp          | action    |
-- +---------+---------------------+-----------+
-- | 3       | 2021-01-06 03:30:46 | timeout   |
-- | 3       | 2021-07-14 14:00:00 | timeout   |
-- | 7       | 2021-06-12 11:57:29 | confirmed |
-- | 7       | 2021-06-13 12:58:28 | confirmed |
-- | 7       | 2021-06-14 13:59:27 | confirmed |
-- | 2       | 2021-01-22 00:00:00 | confirmed |
-- | 2       | 2021-02-28 23:59:59 | timeout   |
-- +---------+---------------------+-----------+
-- Output: 
-- +---------+-------------------+
-- | user_id | confirmation_rate |
-- +---------+-------------------+
-- | 6       | 0.00              |
-- | 3       | 0.00              |
-- | 7       | 1.00              |
-- | 2       | 0.50              |
-- +---------+-------------------+

-- [SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END)  count of confirmed actions
-- COUNT(c.action)	total confirmation attempts
-- ROUND(..., 2)	round to 2 decimals
-- IFNULL(..., 0)	return 0 instead of NULL when there are no attempts
-- ORDER BY s.user_id	matches expected output order]


select s.user_id, ifnull( 
  round( sum (case when c.action="confirmed" then 1 else 0 end) / count(c.action) , 2) , 0
  ) as confirmation_rate 
from Signups s 
left join Confirmations c
on s.user_id=c.user_id 
group by s.user_id;
