# Write your MySQL query statement below

SELECT DISTINCT a.product_id , a.product_name 
FROM Product a JOIN Sales b 
ON a.product_id = b.product_id 
WHERE a.product_id NOT IN (
    SELECT product_id 
    FROM Sales 
    WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31' 
)   
AND b.sale_date BETWEEN '2019-01-01' AND '2019-03-31' ;