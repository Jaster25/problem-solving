SELECT d.name AS 'Department',
       max_e.name AS 'Employee',
       max_e.salary AS 'Salary'
FROM (SELECT e.departmentId,
             e.name,
             e.salary
      FROM employee AS e
      JOIN (SELECT departmentId,
                   MAX(salary) AS salary
            FROM employee
            GROUP BY departmentId) AS max_salary
      ON e.departmentId = max_salary.departmentId
         AND e.salary = max_salary.salary) AS max_e
JOIN department AS d
ON max_e.departmentId = d.id;

-- 

SELECT d.name AS 'Department',
       e.name AS 'Employee',
       e.salary AS 'Salary' 
FROM employee AS e,
	   department AS d 
WHERE e.departmentId = d.id 
      AND (departmentId, salary)
          IN (SELECT departmentId,
                     MAX(Salary) AS max_salary
              FROM employee
              GROUP BY departmentId);