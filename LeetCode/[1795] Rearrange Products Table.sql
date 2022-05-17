SELECT product_id, 'store1' AS store, store1 AS price
FROM Products
WHERE store1 IS NOT NULL

UNION ALL

SELECT product_id, 'store2' AS store, store2 AS price
FROM Products
WHERE store2 IS NOT NULL

UNION ALL

SELECT product_id, 'store3' AS store, store3 AS price
FROM Products
WHERE store3 IS NOT NULL

-- UNION은 두 쿼리의 결과에서 중복되는 값을 삭제하여 나타낸다.
-- UNION ALL은 두 쿼리의 결과에서 중복되는 값을 모두 보여준다.
