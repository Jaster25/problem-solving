
SELECT DISTINCT l1.num AS 'ConsecutiveNums'
FROM logs AS l1,
     logs AS l2,
     logs AS l3
WHERE l1.num = l2.num
      AND l2.num = l3.num
      AND l1.id + 1 = l2.id
      AND l2.id + 1 = l3.id;