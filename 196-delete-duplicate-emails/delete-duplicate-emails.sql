# Write your MySQL query statement below
# Using subquery 
DELETE a
FROM Person a
JOIN Person b
ON a.email = b.email
AND a.id > b.id;