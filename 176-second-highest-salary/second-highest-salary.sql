SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

    /* IFNULL(expression, value_if_null)
    If expression is NOT NULL, return expression.

      If expression IS NULL, return value_if_null.*/
