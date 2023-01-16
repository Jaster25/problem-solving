SELECT MONTH(start_date) AS 'MONTH', car_id AS 'CAR_ID', COUNT(*) AS 'RECORDS'
FROM car_rental_company_rental_history
WHERE car_id in (SELECT car_id
                 FROM car_rental_company_rental_history
                 WHERE MONTH(start_date) BETWEEN 8 AND 10
                 GROUP BY car_id
                 HAVING COUNT(*) >= 5)
      AND MONTH(start_date) BETWEEN 8 AND 10
GROUP BY MONTH(start_date), CAR_ID
ORDER BY MONTH(start_date) ASC, car_id DESC;