-- CASE문
SELECT employee_id,
       CASE
       WHEN employee_id % 2 = 1 AND name NOT like "M%" THEN salary
       ELSE 0
       END AS bonus
FROM employees;

-- IF문
SELECT employee_id,
       IF (employee_id % 2 = 1 AND name NOT LIKE "M%", salary, 0) AS bonus
FROM employees;
