
-- show databases;
use test_db;
-- show tables;
-- these are the tables in test_db database
-- 1. customers
-- 2. order_items
-- 3. orders
-- 4. payment
-- 5. products



-- here's the hierarchy:
-- customers (root parent)
--   ⬇️
-- orders (depends on customers)  ➡️  -- payment (depends on orders )
--   ⬇️
-- order_items (depends on orders)
--   ⬇️
-- products (depends on order_items)




select * from customers

-- select all columns from  customers with last_name as Smith
select * from customers where last_name="Smith"

--customers whose first name starts with J
select * from customers where first_name like "J%"


-- LIKE is an SQL operator used in WHERE clauses to search for a pattern in a string column
-- SELECT * FROM table_name 
-- WHERE column_name LIKE 'pattern';
-- % means any number of characters (including zero).
-- _ means exactly one character.



  
-- sort the customers based on their first name
select * from customers order by first_name asc;


-- sort the table based in city name in descending order
select * from customers order by city desc;

-- inserting one more customer
insert into customers values(16,"Steve","Harrington","steve.harrington@example", "+1(564)223-9876", "1314 Main Lane","Hawkins","TX","USA",76801);
select * from customers

--update cutsomer's email address
update customers set email="olivia.james23@example" where first_name="Olivia";
select * from customers


-- delete the cutsomer whose name is James
-- delete from customers where first_name="James" ;
  
-- Error : because first_name = "James" means customer_id = 7
-- Before deleting it checks, Is there an orders row with customer_id = 7?
-- ✅ Yes → so deleting this customer would orphan that orders row.(in orders table)


-- So,
-- A customer must exist for an order to exist.
-- An order must exist for an order_item to exist.
-- An order_item must exist for a payment to exist.


-- in order to delete any particular customer from customers table you need to delete it from all other tables first(in correct order) 
-- here comes subquery

-- SUBQUERY(or nested query): a SELECT inside another query — it gives you a result that the outer query uses.
-- A mini query inside a bigger query. It runs first → its result is passed to the main (outer) query.


-- here we'll delete that particular customer from all linked tables before deleting it from he customers table



-- #1. delete from payment table
delete from payment where order_id in(
    select order_id from orders where customer_id in(
        select customer_id from customers where first_name="James"
    )
);


-- #2. delete from order_items table 
delete from order_items where order_id in(
    select order_id from orders where customer_id in(
        select customer_id from customers where first_name="James"
    )
);


-- #3. delete from orders table
delete from orders where customer_id in(
    select customer_id from customers where first_name="James"
);


-- finally 
-- #delete from customer table
delete from customers where first_name="James";

select * from customers


--one more important point:
-- while deleting we won't delete from product table as
-- when ypu delete a customer and their order -> You remove order_items → no more link to products.
-- But the product itself stays in the store → because it’s still available for other customers to buy!

--so we won't make any changes in the product table 






-- we'll focus on subqueries in upcoming days more deeply 





-- ALTER TABLE is used to:
-- Add columns
-- Remove columns
-- Rename columns
-- Change column data types
-- Add or drop constraints (like keys, defaults)
-- Rename the table itself

  

-- add Gender column with default Value as Unknown for the time being
alter table customers add column Gender varchar(10) default "Unknown";


-- add date column with default value as today's date
-- alter table customers add column created_at date;

-- Error: we can't directly use "default current_date" as it gives error 
-- because MySQL only allows default expression for TIMESTAMP or DATETIME columns and only for CURRENT_TIMESTAMP
-- so as to have today's date as default value we'll be using CURRENT_TIMESTAMP


alter table customers add column created_at timestamp default CURRENT_TIMESTAMP;
select * from customers




-- if want we can use current_date while insertion 
-- Use DATE + insert manually



  
-- remove the Gender column
alter table customers 
drop column Gender;
select * from customers 




-- MODIFY changes type only.
-- CHANGE can change type and rename the column.



-- change the type of state to char(2)
/**
alter table customers 
modify column state char(2);
select * from customers ;
**/




--rename column and change it's datatype to char(2)

alter table customers
change column state state_code char(2); 
select * from customers ;



-- rename table
alter table customers rename to customers_detail;











