SELECT (CASE WHEN (SELECT COUNT(DISTINCT salary) FROM Employee) < 2 THEN NULL
             ELSE (SELECT DISTINCT salary
                   FROM Employee
                   ORDER BY salary DESC
                   LIMIT 1, 1)
        END) AS SecondHighestSalary;