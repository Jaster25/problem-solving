-- 사용자 정의 변수 사용
-- Runtime: 244 ms, faster than 73.66%
SELECT s.score,
       s_ranking.num AS 'rank'
FROM scores AS s
    JOIN (SELECT s_desc.score,
          (@rank := @rank + 1) AS num
    FROM (SELECT score
          FROM scores
          GROUP BY score
          ORDER BY score DESC) AS s_desc,
         (SELECT @rank := 0) AS r) AS s_ranking
    ON s.score = s_ranking.score
ORDER BY s.score DESC;


-- dense_rank() 메서드 사용
-- Runtime: 218 ms, faster than 98.15%
SELECT score,
       dense_rank() OVER(ORDER BY score DESC) AS 'rank'
FROM scores;

-- @변수는 해당 connect session에서만 유효한 값
-- RANK(): 중복 순위 다음은 해당 개수만큼 건너뛰고 반환
-- DENSE_RANK(): 중복 순위 상관없이 순차적으로 반환
-- ROW_NUMBER(): 중복과 관계 없이 무조건 순서대로 반환