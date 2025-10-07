WITH ranked as (select e.*, DENSE_RANK() over(partition by departmentId order by salary desc) as rn
from Employee e)


select d.name as Department ,e.name as Employee,e.salary as Salary
from ranked e
left join Department d on d.id=e.departmentId
where rn<=3;