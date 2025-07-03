
-- 1731. The Number of Employees Which Report to Each Employee
-- Input: 
-- Employees table:
-- +-------------+---------+------------+-----+
-- | employee_id | name    | reports_to | age |
-- +-------------+---------+------------+-----+
-- | 9           | Hercy   | null       | 43  |
-- | 6           | Alice   | 9          | 41  |
-- | 4           | Bob     | 9          | 36  |
-- | 2           | Winston | null       | 37  |
-- +-------------+---------+------------+-----+
-- Output: 
-- +-------------+-------+---------------+-------------+
-- | employee_id | name  | reports_count | average_age |
-- +-------------+-------+---------------+-------------+
-- | 9           | Hercy | 2             | 39          |
-- +-------------+-------+---------------+-------------+  

-- (e1 = manager | e2 = employee who reports to manager | e2.reports_to = e1.employee_id → gets all direct reports for each manager)
select e1.employee_id, e1.name, count(e2.reports_to) as reports_count, round(avg(e2.age),0) as average_age 
from Employees e1 join Employees e2 on e1.employee_id=e2.reports_to
group by e1.employee_id, e1.name
order by e1.employee_id, e2.age desc;








-- 1789. Primary Department for Each Employee
-- Input: 
-- Employee table:
-- +-------------+---------------+--------------+
-- | employee_id | department_id | primary_flag |
-- +-------------+---------------+--------------+
-- | 1           | 1             | N            |
-- | 2           | 1             | Y            |
-- | 2           | 2             | N            |
-- | 3           | 3             | N            |
-- | 4           | 2             | N            |
-- | 4           | 3             | Y            |
-- | 4           | 4             | N            |
-- +-------------+---------------+--------------+
-- Output: 
-- +-------------+---------------+
-- | employee_id | department_id |
-- +-------------+---------------+
-- | 1           | 1             |
-- | 2           | 1             |
-- | 3           | 3             |
-- | 4           | 3             |
-- +-------------+---------------+
  
-- select employee_id , department_id from Employee 
-- where (employee_id, primary_flag) in (
--     select employee_id , 
--         case 
--             when count(case when primary_flag='Y' then 1 end)>0 then 'Y'
--             else 'N' 
--             end
--         from employee
--         group by employee_id
-- );

-- //optimal
select employee_id , department_id from Employee 
where primary_flag='Y' or employee_id in (
    select employee_id from employee
    group by employee_id
    having count(employee_id)=1
);
-- (If an employee has a row where primary_flag = 'Y', take it.
-- If an employee has only one department (i.e. only one row total), take that — even if it’s not marked 'Y'.)








-- 1978. Employees Whose Manager Left the Company
--   Input:  
-- Employees table:
-- +-------------+-----------+------------+--------+
-- | employee_id | name      | manager_id | salary |
-- +-------------+-----------+------------+--------+
-- | 3           | Mila      | 9          | 60301  |
-- | 12          | Antonella | null       | 31000  |
-- | 13          | Emery     | null       | 67084  |
-- | 1           | Kalel     | 11         | 21241  |
-- | 9           | Mikaela   | null       | 50937  |
-- | 11          | Joziah    | 6          | 28485  |
-- +-------------+-----------+------------+--------+
-- Output: 
-- +-------------+
-- | employee_id |
-- +-------------+
-- | 11          |
-- +-------------+

select employee_id from Employees 
where salary < 30000 and 
manager_id not in (select employee_id from Employees)
order by employee_id;








-- 610. Triangle Judgement
--   Input: 
-- Triangle table:
-- +----+----+----+
-- | x  | y  | z  |
-- +----+----+----+
-- | 13 | 15 | 30 |
-- | 10 | 20 | 15 |
-- +----+----+----+
-- Output: 
-- +----+----+----+----------+
-- | x  | y  | z  | triangle |
-- +----+----+----+----------+
-- | 13 | 15 | 30 | No       |
-- | 10 | 20 | 15 | Yes      |
-- +----+----+----+----------+
select x,y,z,(case when (x+y>z && y+z>x && x+z>y) then 'Yes' else 'No' end) as triangle from Triangle ;







-- 1527. Patients With a Condition
-- Input: 
-- Patients table:
-- +------------+--------------+--------------+
-- | patient_id | patient_name | conditions   |
-- +------------+--------------+--------------+
-- | 1          | Daniel       | YFEV COUGH   |
-- | 2          | Alice        |              |
-- | 3          | Bob          | DIAB100 MYOP |
-- | 4          | George       | ACNE DIAB100 |
-- | 5          | Alain        | DIAB201      |
-- +------------+--------------+--------------+
-- Output: 
-- +------------+--------------+--------------+
-- | patient_id | patient_name | conditions   |
-- +------------+--------------+--------------+
-- | 3          | Bob          | DIAB100 MYOP |
-- | 4          | George       | ACNE DIAB100 | 
-- +------------+--------------+--------------+
-- (Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with 'DIAB1' prefix.)
  
select patient_id , patient_name, conditions from Patients
where conditions like 'DIAB1' or 
  conditions like 'DIAB1%' or 
  conditions like '% DIAB1%';

