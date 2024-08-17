# Write your MySQL query statement below
SELECT e1.name
FROM Employee AS e1
JOIN (
    SELECT managerId,COUNT(managerId) AS direct_reports
    FROM Employee
    GROUP BY managerId
    -- HAVING direct_reports>=5
) AS e2
ON e1.id=e2.managerId AND e2.direct_reports>=5 ;
