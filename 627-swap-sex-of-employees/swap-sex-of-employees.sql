# Write your MySQL query statement below
# Simple update query using case 

UPDATE Salary 
SET sex = 
    CASE 
        WHEN sex = 'm' THEN 'f'
        ELSE 'm'
END ;  