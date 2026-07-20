# Write your MySQL query statement below

SELECT b.name AS Department , a.name AS Employee , a.salary AS Salary 
FROM Employee a JOIN Department b
ON a.departmentId = b.id 
WHERE (a.departmentId , a.salary) IN (
    SELECT departmentId , max(salary) 
    FROM Employee 
    GROUP BY departmentId 
); 