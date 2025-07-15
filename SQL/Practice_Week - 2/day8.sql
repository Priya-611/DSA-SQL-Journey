-- 3436. Find Valid Emails
-- Input:
-- Users table:
-- +---------+---------------------+
-- | user_id | email               |
-- +---------+---------------------+
-- | 1       | alice@example.com   |
-- | 2       | bob_at_example.com  |
-- | 3       | charlie@example.net |
-- | 4       | david@domain.com    |
-- | 5       | eve@invalid         |
-- +---------+---------------------+
-- Output:

-- +---------+-------------------+
-- | user_id | email             |
-- +---------+-------------------+
-- | 1       | alice@example.com |
-- | 4       | david@domain.com  |
-- +---------+-------------------+

select user_id,email from Users where email regexp '^[A-Za-z0-9]+@+[A-Za-z]+\\.com$';







