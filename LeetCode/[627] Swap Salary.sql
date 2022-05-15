-- CASE문
UPDATE salary
SET sex = CASE
          WHEN (sex='m') THEN 'f'
          WHEN (sex='f') THEN 'm'
          END;

UPDATE salary
SET sex = CASE sex
          WHEN 'm' THEN 'f'
          ELSE 'm'
          END;

-- IF문
UPDATE salary
SET sex = IF (sex = 'm', 'f', 'm');