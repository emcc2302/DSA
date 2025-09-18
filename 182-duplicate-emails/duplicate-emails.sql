# Write your MySQL query statement below
SELECT DISTINCT e1.email AS Email
from Person e1
JOIN Person e2 ON e1.email=e2.email
AND e1.id <> e2.id;