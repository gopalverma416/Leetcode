select w.id 
from Weather w
left join Weather s on DATEDIFF(w.recordDate,s.recordDate)=1
where w.temperature> s.temperature;

