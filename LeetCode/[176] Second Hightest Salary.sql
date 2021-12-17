-- Runtime: 191 ms
SELECT (CASE
            WHEN (SELECT COUNT(DISTINCT salary)
                  FROM employee) < 2
            THEN NULL
            ELSE (SELECT salary
                  FROM employee
                  ORDER BY salary DESC
                  LIMIT 1, 1)
        END) AS SecondHighestSalary;