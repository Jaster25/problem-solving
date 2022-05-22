SELECT u.name AS "name",
       IF (SUM(r.distance) IS NOT NULL, SUM(r.distance), 0) AS "travelled_distance"
FROM Users u
LEFT JOIN Rides r
ON U.id = r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC,
         name ASC;