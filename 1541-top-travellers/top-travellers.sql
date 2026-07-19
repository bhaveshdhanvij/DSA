# Write your MySQL query statement below

SELECT a.name , COALESCE(SUM(b.distance) , 0) as travelled_distance 
FROM Users a LEFT JOIN Rides b 
ON a.id = b.user_id
GROUP BY a.id 
ORDER BY travelled_distance DESC , a.name ASC ;