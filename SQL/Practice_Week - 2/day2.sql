-- 182. Duplicate Emails
-- Input: 
-- Person table:
-- +----+---------+
-- | id | email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- Output: 
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+

select email as Email from Person
group by email 
having count(email)>=2;







-- 1693. Daily Leads and Partners
-- Input: 
-- DailySales table:
-- +-----------+-----------+---------+------------+
-- | date_id   | make_name | lead_id | partner_id |
-- +-----------+-----------+---------+------------+
-- | 2020-12-8 | toyota    | 0       | 1          |
-- | 2020-12-8 | toyota    | 1       | 0          |
-- | 2020-12-8 | toyota    | 1       | 2          |
-- | 2020-12-7 | toyota    | 0       | 2          |
-- | 2020-12-7 | toyota    | 0       | 1          |
-- | 2020-12-8 | honda     | 1       | 2          |
-- | 2020-12-8 | honda     | 2       | 1          |
-- | 2020-12-7 | honda     | 0       | 1          |
-- | 2020-12-7 | honda     | 1       | 2          |
-- | 2020-12-7 | honda     | 2       | 1          |
-- +-----------+-----------+---------+------------+
-- Output: 
-- +-----------+-----------+--------------+-----------------+
-- | date_id   | make_name | unique_leads | unique_partners |
-- +-----------+-----------+--------------+-----------------+
-- | 2020-12-8 | toyota    | 2            | 3               |
-- | 2020-12-7 | toyota    | 1            | 2               |
-- | 2020-12-8 | honda     | 2            | 2               |
-- | 2020-12-7 | honda     | 3            | 2               |
-- +-----------+-----------+--------------+-----------------+
select date_id, make_name,count(distinct lead_id) as unique_leads,count(distinct partner_id) as unique_partners 
from DailySales
group by date_id, make_name
order by date_id;






-- 1907. Count Salary Categories
-- Input: 
-- Accounts table:
-- +------------+--------+
-- | account_id | income |
-- +------------+--------+
-- | 3          | 108939 |
-- | 2          | 12747  |
-- | 8          | 87709  |
-- | 6          | 91796  |
-- +------------+--------+
-- Output: 
-- +----------------+----------------+
-- | category       | accounts_count |
-- +----------------+----------------+
-- | Low Salary     | 1              |
-- | Average Salary | 0              |
-- | High Salary    | 3              |
-- +----------------+----------------+
/*
select category , count(*) as accounts_count from (
             select case when income<20000 then "Low Salary"
             when income<=20000 and income>=50000 then "Average Salary"
             when income>50000 then "High Salary" end as category from Account
) as c group by category;
*/
-- (above solution doesn't include count as 0)
--optimal
select "Low Salary" as category, count(*) as accounts_count from Accounts where income<20000
union
select "Average Salary" as category ,count(*) as accounts_count from Accounts where income>=20000 and income <=50000
union
select "High Salary" as category ,count(*) as accounts_count from Accounts where income>50000;








-- 626. Exchange Seats
-- Input: 
-- Seat table:
-- +----+---------+
-- | id | student |
-- +----+---------+
-- | 1  | Abbot   |
-- | 2  | Doris   |
-- | 3  | Emerson |
-- | 4  | Green   |
-- | 5  | Jeames  |
-- +----+---------+
-- Output: 
-- +----+---------+
-- | id | student |
-- +----+---------+
-- | 1  | Doris   |
-- | 2  | Abbot   |
-- | 3  | Green   |
-- | 4  | Emerson |
-- | 5  | Jeames  |
-- +----+---------+

-- (if id is even set id as id-1  , and if id is odd set id as id+1 [only if id+1 exist in table])
select case when id%2=1 and id+1 in(select id from Seat)  then id+1
            when id%2=0 then id-1
            else id
end as id, student from Seat
order by id;

