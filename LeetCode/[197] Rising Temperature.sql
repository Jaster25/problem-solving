SELECT w1.id
FROM weather w1 INNER JOIN weather w2
    ON w1.recordDate = ADDDATE(w2.recordDate, INTERVAL 1 DAY)
    AND w1.temperature > w2.temperature;

SELECT w1.id
FROM weather w1 INNER JOIN weather w2
    ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
    AND w1.temperature > w2.temperature;
