SELECT
    (CASE
        WHEN MOD(id, 2) = 0 THEN id - 1 
        WHEN MOD(id, 2) = 1 AND id = max_count THEN id
        ELSE id + 1
    END) AS id,
    student
FROM seat,
    (SELECT COUNT(*) AS max_count
    FROM seat) AS seat_count
ORDER BY id ASC;
