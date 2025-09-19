SELECT 
    c.name AS Customers            -- un customers ka name
FROM Customers c
LEFT JOIN Orders o
    ON c.id = o.customerId         -- join by customerId
WHERE o.id IS NULL;                -- jaha order nahi hai