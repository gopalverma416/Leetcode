select name
from 
employee e
where e.id IN (
    select s.managerId
    from employee s
    group by s.managerId
    having count(*)>=5
)