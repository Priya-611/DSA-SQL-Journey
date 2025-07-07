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




