
-- 1341. Movie Rating
--   Input: 
-- Movies table:
-- +-------------+--------------+
-- | movie_id    |  title       |
-- +-------------+--------------+
-- | 1           | Avengers     |
-- | 2           | Frozen 2     |
-- | 3           | Joker        |
-- +-------------+--------------+
-- Users table:
-- +-------------+--------------+
-- | user_id     |  name        |
-- +-------------+--------------+
-- | 1           | Daniel       |
-- | 2           | Monica       |
-- | 3           | Maria        |
-- | 4           | James        |
-- +-------------+--------------+
-- MovieRating table:
-- +-------------+--------------+--------------+-------------+
-- | movie_id    | user_id      | rating       | created_at  |
-- +-------------+--------------+--------------+-------------+
-- | 1           | 1            | 3            | 2020-01-12  |
-- | 1           | 2            | 4            | 2020-02-11  |
-- | 1           | 3            | 2            | 2020-02-12  |
-- | 1           | 4            | 1            | 2020-01-01  |
-- | 2           | 1            | 5            | 2020-02-17  | 
-- | 2           | 2            | 2            | 2020-02-01  | 
-- | 2           | 3            | 2            | 2020-03-01  |
-- | 3           | 1            | 3            | 2020-02-22  | 
-- | 3           | 2            | 4            | 2020-02-25  | 
-- +-------------+--------------+--------------+-------------+
-- Output: 
-- +--------------+
-- | results      |
-- +--------------+
-- | Daniel       |
-- | Frozen 2     |
-- +--------------+
-- Explanation: 
-- Daniel and Monica have rated 3 movies ("Avengers", "Frozen 2" and "Joker") but Daniel is smaller lexicographically.
-- Frozen 2 and Joker have a rating average of 3.5 in February but Frozen 2 is smaller lexicographically.

(select u.name as results from Users u join MovieRating m 
  on u.user_id=m.user_id 
  group by u.user_id 
  order by count(*) desc,u.name limit 1
  )
union all
(select mv.title as results from Movies mv join MovieRating m 
  on mv.movie_id=m.movie_id where 
  year(created_at)=2020 and month(created_at) =2 
  group by mv.movie_id 
  order by avg(m.rating) desc,mv.title limit 1
)

/*union removes duplicate while union all keeps duplicate  */






-- 602. Friend Requests II: Who Has the Most Friends
-- Input: 
-- RequestAccepted table:
-- +--------------+-------------+-------------+
-- | requester_id | accepter_id | accept_date |
-- +--------------+-------------+-------------+
-- | 1            | 2           | 2016/06/03  |
-- | 1            | 3           | 2016/06/08  |
-- | 2            | 3           | 2016/06/08  |
-- | 3            | 4           | 2016/06/09  |
-- +--------------+-------------+-------------+
-- Output: 
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 3  | 3   |
-- +----+-----+
-- Explanation: 
-- The person with id 3 is a friend of people 1, 2, and 4, so he has three friends in total, which is the most number than any others.

with new as(select requester_id as id from RequestAccepted union all select accepter_id as id from RequestAccepted)
select id ,count(*) as num from new group by id order by num desc limit 1;







-- 1204. Last Person to Fit in the Bus
-- Input: 
-- Queue table:
-- +-----------+-------------+--------+------+
-- | person_id | person_name | weight | turn |
-- +-----------+-------------+--------+------+
-- | 5         | Alice       | 250    | 1    |
-- | 4         | Bob         | 175    | 5    |
-- | 3         | Alex        | 350    | 2    |
-- | 6         | John Cena   | 400    | 3    |
-- | 1         | Winston     | 500    | 6    |
-- | 2         | Marie       | 200    | 4    |
-- +-----------+-------------+--------+------+
-- Output: 
-- +-------------+
-- | person_name |
-- +-------------+
-- | John Cena   |
-- +-------------+
-- Explanation: The folowing table is ordered by the turn for simplicity.
-- +------+----+-----------+--------+--------------+
-- | Turn | ID | Name      | Weight | Total Weight |
-- +------+----+-----------+--------+--------------+
-- | 1    | 5  | Alice     | 250    | 250          |
-- | 2    | 3  | Alex      | 350    | 600          |
-- | 3    | 6  | John Cena | 400    | 1000         | (last person to board)
-- | 4    | 2  | Marie     | 200    | 1200         | (cannot board)
-- | 5    | 4  | Bob       | 175    | ___          |
-- | 6    | 1  | Winston   | 500    | ___          |
-- +------+----+-----------+--------+--------------+

select q1.person_name from Queue q1 join Queue q2 on q1.turn >=q2.turn
group by q1.turn having sum(q2.weight)<=1000 
order by sum(q2.weight) desc limit 1;  --the heighest cumulative  sum i.e person with last sum is chosen
/* here self join is performed i.e. each q.turn will hav e each q2.turn [1 -> 1,2,3,4 : 2 -> 1,2,3,4 ]
but due to condition q1.turn >= q2.turn [it will have only following values:  [1 -> 1 : 2 -> 1,2 ]  and only with these turns the wieght and sum is calculated
| q1.person\_name | q1.turn | Matching q2.turns (≤ q1.turn) | q2.weights            | Cumulative Weight |
| --------------- | ------- | ----------------------------- | --------------------- | ----------------- |
| Alice           | 1       | 1                             | 300                   | 300 ✅             |
| Bob             | 2       | 1, 2                          | 300 + 400             | 700 ✅             |
| Charlie         | 3       | 1, 2, 3                       | 300 + 400 + 350       | **1050 ❌**        |
| Dave            | 4       | 1, 2, 3, 4                    | 300 + 400 + 350 + 300 | **1350 ❌**        |

*/
