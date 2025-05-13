# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE description != 'boring' AND id IN(
    SELECT id from Cinema
    where id % 2 = 1
)
ORDER BY rating DESC;
