-- MySQL Limit문에서는 산술 연산자가 있는 표현을 인식 못한다.

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M = N - 1;
  RETURN (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT M, 1 -- LIMIT N - 1, 1 인식 못함
  );
END