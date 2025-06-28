select * from customers
-- String functions: manipulate text values in your database — like names, codes, emails, etc.
-- 1. LENGTH() or CHAR_LENGTH()  -->  Returns number of characters.
-- 2. UPPER() and LOWER() --> Converts text to all upper or lower case.
-- 3. TRIM(), LTRIM(), RTRIM() --> Removes spaces.
-- 4. SUBSTRING() or SUBSTR() --> Extract part of the string.
-- 5. REPLACE() -->  Replace part of a string.
-- 6. CONCAT() and CONCAT_WS() --> Join multiple strings.
-- 7. INSTR() or POSITION() --> Find position of a substring.
-- 8. LEFT() and RIGHT() --> Get first or last few characters.
-- 9. REPEAT() --> Repeat a string n times.
-- 10. REVERSE() --> Reverse a string.

  
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





