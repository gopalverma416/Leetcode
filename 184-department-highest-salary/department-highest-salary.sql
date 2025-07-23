WITH DepartementMaxSalary AS (
    SELECT departmentId,max(salary) AS max_salary
    FROM Employee 
    group by departmentId
)

SELECT 
d.name AS Department,
e.name as Employee,
e.salary as Salary
FROM
Employee e
JOIN 
Department d ON e.departmentId=d.id
JOIN
DepartementMaxSalary ms ON e.departmentId=ms.departmentId
AND
e.salary=ms.max_salary;
