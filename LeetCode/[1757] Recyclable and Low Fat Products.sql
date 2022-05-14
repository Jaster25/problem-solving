SELECT product_id
FROM Products
WHERE low_fats = "Y"
      AND recyclable = "Y"

-- Write a query to get the percentage of certain products
SELECT ROUND(AVG(CASE WHEN low_fats = 'Y' AND recyclable = 'Y' THEN 1 ELSE 0 END), 2) AS PERCENTAGE
FROM Products
-- ROUND( , 2): 2번째 소수자리 밑에 반올림