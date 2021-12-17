--  같지 않다: <>, !=
SELECT *
FROM cinema
WHERE id % 2 <> 0
      AND description NOT LIKE 'boring'
ORDER BY rating DESC;

-- 

SELECT *
FROM cinema
WHERE MOD(id, 2) = 1
      AND description != 'boring'
ORDER BY rating DESC;

--

SELECT *
FROM cinema
WHERE id % 2 = 1
      AND description <> 'boring'
ORDER BY rating DESC;