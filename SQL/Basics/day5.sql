-- JOIN: used to combine rows from two or more tables based on a related column between them — usually a primary key in one table and a foreign key in another.

-- Relational databases are built using multiple related tables, not one giant table.
-- JOINs allow you to:
-- Merge them together temporarily
-- Answer complex questions

-- Types:
-- Type	                                Description                                                     	Returns
-- INNER JOIN	                        Matches only rows with matching keys in both tables                 Only matching rows
-- LEFT JOIN (LEFT OUTER JOIN)     	  All rows from the left table + matching rows from right table       NULL where no match
-- RIGHT JOIN (RIGHT OUTER JOIN)	    All rows from right table + matching rows from left                 NULL where no match
-- FULL JOIN (FULL OUTER JOIN)     	  All rows from both tables                                           NULL where no match
-- CROSS JOIN	                        All possible combinations (Cartesian product)                       Multiplication of rows



-- INNER JOIN
select c.customername, o.orderdate from customers as c 
inner join orders as o on c.customernumber = o.customernumber;
-- (Only shows customers who placed orders with order date )


-- LEFT JOIN
select c.customername, o.orderdate from customers as c 
left join orders as o on c.customernumber = o.customernumber;
-- (all customers (from left customer table) and only matching data from order table )
-- (Shows all customers, even if they didn’t place any orders) [ for customer without orde it show -> no data]


-- RIGHT JOIN
select c.customername, o.orderdate from customers as c 
right join orders as o on c.customernumber = o.customernumber;
-- (all data from right table(orders) and matching data from left table (cutsomers))
-- (Shows all orders, even if the customer isn’t in the customers table)


-- FULL JOIN
select c.customername, o.orderdate from customers as c
full outer join orders as o on c.customernumber = o.customernumber;
-- (Shows everything — all customers and all orders)


-- CROSS JOIN
select c.customername, o.orderdate from  customers as c
cross join orders as o;
-- (Returns every possible combination → not often useful for business queries)




-- #Examples:
-- Complete order info with customer name, product, quantity, and price.
-- (inner join order table, customers table and order_details table )
select 
c.customername, o.ordernumber, o.orderdate, od.productcode, od.quantityordered, od.priceeach
from customers as c
inner join orders as o on o.customernumber = c.customernumber 
inner join order_details as od on o.ordernumber = od.ordernumber




-- Customers who didn’t place any order
-- (order number is null means no order)
select c.customername from customers as c 
left join orders as o on c.customernumber = o.customernumber 
where o.ordernumber is null;



-- (Show all orders placed by customers from Germany)
select c.customername, o.ordernumber, o.orderdate from customers as c
inner join orders as o on c.customernumber= o.customernumber where c.country="USA";


-- (Get each customer's total number of orders)
Select c.customername, count(o.ordernumber) from customers as c 
left join orders as o on c.customernumber = o.customernumber
group by c.customername;



-- (Show each order with its product details and total line amount)
select o.ordernumber , od.productcode, od.quantityordered, od.priceeach ,(od.quantityordered * od.priceeach) as line_total from orders as o
inner join order_details as od on o.ordernumber= od.ordernumber;



-- (Get the total sales value for each customer)
select c.customername , sum(od.quantityordered * od.priceeach) as total_sales from customers as c 
inner join orders as o on o.customernumber= c.customernumber
inner join order_details as od on od.ordernumber = o.ordernumber
group by c.customername;



-- (Get total sales per customer, then filter:)
-- (customer with total sales more than 100000)
select customername, total_sales from(
select c.customername , sum(od.quantityordered * od.priceeach) as total_sales from customers as c
inner join orders as o on c.customernumber = o.customernumber 
inner join order_details as od on o.ordernumber = od.ordernumber
group by c.customername
) as sales_data
where total_sales > 100000;



-- (Orders that have order details)
SELECT ordernumber from orders where ordernumber in (
    select distinct ordernumber from order_details
);
/**
DISTINCT is used to remove duplicate values from the result of a SELECT query.
 It tells SQL: “Only give me unique results!”
**/



-- (Customers who have placed orders but none of them had more than 30 items)
select customername from customers where customernumber in( 
    select customernumber from orders where ordernumber in(
        select ordernumber from order_details group by ordernumber having sum(quantityordered) <=30
    )
);




-- (Customers who have placed orders for more than one product)
SELECT customername from customers where customernumber in(
    select customernumber from orders where ordernumber in(
        SELECT ordernumber from order_details group by ordernumber having count(productcode) > 1
    )
);



-- SUBQUERIES using in/not in

SELECT customername from customers where customernumber in(
    select distinct customernumber from orders);

SELECT customername from customers where customernumber not in(
    select distinct customernumber from orders);



-- correlated(depends on outer query)
-- This links c1 and c2 by country, dynamically comparing row by row.
SELECT customername,country,creditlimit from customers c1 where creditlimit>(
    select avg(creditlimit) from customers c2 where c1.country = c2.country
)



-- using subquery using from (derived table)
SELECT * from(
    select customernumber , sum(quantityordered *priceeach) as total from orders as o 
    join order_details as od on o.ordernumber= od.ordernumber 
    group by customernumber
) as total_table
where total>100000;



-- Using subquery in SELECT (computed column)
select customername, (SELECT count(*) from orders as o where o.customernumber= c.customernumber) as order_count from customers as c;


