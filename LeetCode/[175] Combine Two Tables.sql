-- Runtime: 416 ms, faster than 31.39%
SELECT P.FirstName, P.LastName, A.City, A.State
FROM Person P LEFT JOIN Address A
ON P.PersonId = A.PersonId;

-- Runtime: 315 ms, faster than 86.84%
SELECT P.FirstName, P.LastName, A.City, A.State
FROM Person P LEFT OUTER JOIN Address A
ON P.PersonId = A.PersonId;

-- 같은 의미의 코드