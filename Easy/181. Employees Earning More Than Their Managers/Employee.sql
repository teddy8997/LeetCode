# Write your MySQL query statement below
SELECT e1.Name as Employee
FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id and e1.Salary > e2. Salary