# Write your MySQL query statement below

(SELECT a.name AS results 
FROM Users a JOIN MovieRating b 
ON a.user_id = b.user_id
GROUP BY a.user_id , a.name 
ORDER BY COUNT(*) DESC , a.name ASC 
LIMIT 1 )
UNION ALL
(SELECT a.title as results 
FROM Movies a JOIN MovieRating b 
ON a.movie_id = b.movie_id 
WHERE b.created_at BETWEEN '2020-02-01' AND '2020-02-29' 
GROUP BY a.movie_id , a.title 
ORDER BY AVG(b.rating) DESC , a.title ASC 
LIMIT 1 );