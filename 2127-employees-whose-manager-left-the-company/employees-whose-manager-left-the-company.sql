select employee_id 
from Employees 
where salary <30000 AND manager_id IS NOT NULL and manager_id NOT IN (
    SELECT  employee_id from Employees
)
order by employee_id;
