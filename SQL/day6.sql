
-- String functions: manipulate text values in your database — like names, codes, emails, etc.
  /*
1. LENGTH() or CHAR_LENGTH()  -->  Returns number of characters.
2. UPPER() and LOWER() --> Converts text to all upper or lower case.
3. TRIM(), LTRIM(), RTRIM() --> Removes spaces.
4. SUBSTRING() or SUBSTR() --> Extract part of the string.
5. REPLACE() -->  Replace part of a string.
6. CONCAT() and CONCAT_WS() --> Join multiple strings.
7. INSTR() or POSITION() --> Find position of a substring.
8. LEFT() and RIGHT() --> Get first or last few characters.
9. REPEAT() --> Repeat a string n times.
10. REVERSE() --> Reverse a string. */

select * from customers;

-- (finding length  of customer name)
select customername, length(customername) from customers;
select customername, char_length(customername) from customers;

-- (changing in upper and lower case)
select upper(customername) from customers;
SELECT lower(customername) from customers;

-- (removing all extra spaces)
select trim('     hello sql     ');      -- 'hello sql'    (remove extra spaces)
select  ltrim('   hello  ');             -- 'hello  '      (remove extra spaces from left)
select rtrim('  hello     ');            -- '  hello'      (remove extra spaces from right)

-- (extract substring from country [from 1st char , extract three characters])
select substring(country,1 ,3) as country_code from customers;
select substr(country,1 ,3) as country_code from customers;

-- (replacing USa by India)
SELECT customername, country, replace(country, "USA" ,"India") as updated_country from customers;

-- (concatenating country and state by '-')
select concat(country,'-',state) as country-state from customers;

-- (concatenating city, country and state by '-')
select concat_ws('-',city,country,state) from customers;         --    city-country-state

-- (finding position of second parameter in first parameter)
select position(" Gran" in "Hermione Granger");
select instr("Hermione Granger"," Gran");

-- (extracting 3 left characters  and 3 right characters)
select left(country,3) from customers;
select right(ordernumber,3) from order_details;

-- (repeating city name 3 times)
select repeat(city, 3) from customers;

-- (reversing country name's characters)
select reverse(country) from customers;





-- Numeric functions: help perform mathematical operations or format numbers in your query results.
/*
1. ROUND(number, decimals) --> Rounds a number to a given number of decimal places.
2. FLOOR(number) --> Rounds down to the nearest whole number.
3. CEIL(number) or CEILING(number) --> Rounds up to the nearest whole number.
4. ABS(number) --> Returns the absolute (positive) value.
5. MOD(x, y) or x % y --> Returns the remainder of division.
6. POWER(x, y) or POW(x, y) --> Raises x to the power y.
7. SQRT(x) --> Returns the square root.
8. RAND() or RAND(seed) --> Generates a random number between 0 and 1.
9. SIGN(x) Returns: 1 (if positive) ,-1 (if negative) ,0 (if zero).  */


select * from order_details;

-- (rounds price each to 1 decimal place)
select round(priceeach,1) from order_details;

SELECT ordernumber, ROUND(SUM(quantityordered * priceeach), 2) AS total_cost
FROM order_details
GROUP BY ordernumber;

-- (rounds down priceeach to nearest whole no.)
select floor(priceeach) from order_details;

-- (rounds up price each to nearest whole no.)
SELECT ceiling(priceeach) from order_details;
SELECT ceil(priceeach) from order_details;

-- (returns absolute positive value)
SELECT abs(-25);          --25

-- (returns remainder 10%3)
SELECT mod(10,3);

-- (returns  x raised to power y)
select pow(2,3);
SELECT power(2,3);

-- (returns square root )
select sqrt(81);

-- (generate a random no. between 0 to 1)
SELECT rand();

-- (returns sign of the number)
SELECT sign(-12);        -- -1
SELECT sign(13);         -- 1
SELECT sign(0);          -- 0





-- Conversion Functions: These help you convert data types, for example from string → integer, float → string, etc.
/*
1. CAST(value AS datatype)  datatype as in (STRING, INT, DECIMAL, DOUBLE, BOOLEAN, DATE, DATETIME, TIME, GYEAR, GYEARMONTH)
2. CONVERT(value, datatype) (MySQL-specific)
3. FORMAT(value, decimal place) Formatting Numbers (optional in MySQL)    */


-- (convert creditlimit into string format)
select cast(creditlimit as string) as string_limit from customers;
-- SELECT CAST('123' AS INT);


-- (conversion using convert)
SELECT convert(creditlimit, string) from customers;
-- SELECT CONVERT('2024-01-01', DATE);


-- (formatting crditlimit upto 3 decimal place using format)
select format(creditlimit, 3) from customers;



