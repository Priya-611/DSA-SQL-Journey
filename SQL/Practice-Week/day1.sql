-- 181. Employees Earning More Than Their Managers
--using inner join
-- Employee table:
-- +----+-------+--------+-----------+
-- | id | name  | salary | managerId |
-- +----+-------+--------+-----------+
-- | 1  | Joe   | 70000  | 3         |
-- | 2  | Henry | 80000  | 4         |
-- | 3  | Sam   | 60000  | Null      |
-- | 4  | Max   | 90000  | Null      |
-- +----+-------+--------+-----------+

select e.name as Employee
from Employee e 
join Employee m on m.id=e.managerId
where e.salary > m.salary;





-- 176. Second Highest Salary
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+

select max(salary) as SecondHighestSalary from Employee
where salary != (select max(salary) from Employee);






-- 183. Customers Who Never Order
-- Customers table:
-- +----+-------+
-- | id | name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- Orders table:
-- +----+------------+
-- | id | customerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+

select c.name as Customers from Customers c
where c.id not in (select o.customerId from Orders o) ;






-- 184. Department Highest Salary
-- Employee table:
-- +----+-------+--------+--------------+
-- | id | name  | salary | departmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Jim   | 90000  | 1            |
-- | 3  | Henry | 80000  | 2            |
-- | 4  | Sam   | 60000  | 2            |
-- | 5  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+
-- Department table:
-- +----+-------+
-- | id | name  |
-- +----+-------+
-- | 1  | IT    |
-- | 2  | Sales |
-- +----+-------+

select d.name as Department , e.name as Employee, e.salary as Salary 
from Employee e 
join Department d 
on e.departmentId=d.id 
where e.salary = (
    select max(e.salary) from Employee e where e.departmentId=d.Id
);





-- 196. Delete Duplicate Emails
-- Person table:
-- +----+------------------+
-- | id | email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- | 3  | john@example.com |
-- +----+------------------+

(Wrong) delete from Person where id not in (select min(id) from Person group by email ); 
-- SQL doesn't allow reading from and modifying the same table (Person) in a subquery of a DELETE.
delete from Person where id not in( 
  select min_id from(
    select min(id) as min_id from Person group by email 
  )as temp
);





-- 197. Rising Temperature
 -- find all dates' id with higher temperatures compared to its previous dates (yesterday).
 -- [such that difference of both date is 1 and today's temp > yesterday's temp]

-- Weather table:
-- +----+------------+-------------+
-- | id | recordDate | temperature |
-- +----+------------+-------------+
-- | 1  | 2015-01-01 | 10          |
-- | 2  | 2015-01-02 | 25          |
-- | 3  | 2015-01-03 | 20          |
-- | 4  | 2015-01-04 | 30          |
-- +----+------------+-------------+

select w1.id from Weather w1 join Weather w2 
where datediff(w1.recordDate,w2.recordDate)=1 and w1.temperature >w2.temperature;


