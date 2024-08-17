# Write your MySQL query statement below
SELECT b.id
FROM Weather AS a
JOIN Weather AS b
ON DATEDIFF(b.recordDate,a.recordDate)=1 AND b.temperature>a.temperature;
