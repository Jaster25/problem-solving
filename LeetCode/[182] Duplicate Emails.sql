SELECT email AS Email
FROM person
GROUP BY email
HAVING COUNT(*) > 1;