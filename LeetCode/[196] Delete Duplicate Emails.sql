-- Runtime: 916 ms
DELETE p1
FROM person p1, person p2
WHERE p1.email = p2.email
    AND p1.id > p2.id;

-- Runtime: 504 ms
DELETE
FROM person
WHERE id NOT IN (
    SELECT min_person.min_id
    FROM (
        SELECT email, MIN(id) AS min_id
        FROM person
        GROUP BY email
    ) AS min_person
)