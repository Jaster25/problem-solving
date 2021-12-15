SELECT e1.name AS Employee
FROM employee AS e1 INNER JOIN employee AS e2
    ON e1.managerId = e2.id
    AND e1.salary > e2.salary;
    
SELECT e1.name AS Employee
FROM employee AS e1, employee AS e2
WHERE e1.managerId = e2.id
    AND e1.salary > e2.salary;
