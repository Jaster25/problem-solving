SELECT DISTINCT t1.id,
       CASE WHEN t1.p_id IS NULL THEN 'Root'
            WHEN t1.p_id IS NOT NULL AND t2.id is NOT NULL THEN 'Inner'
            ELSE 'Leaf'
       END AS type
FROM Tree t1
LEFT JOIN Tree t2
ON t1.id = t2.p_id;

-- Join 안써서 살짝 느림
SELECT id,
       CASE WHEN p_id IS NULL THEN 'Root'
            WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
            ELSE 'Leaf'
       END AS type
FROM Tree;
