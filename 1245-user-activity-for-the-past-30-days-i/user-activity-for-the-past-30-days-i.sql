select activity_date as day,count(distinct user_id) as active_users
from Activity as a 
where activity_date Between Date_Sub('2019-07-27', interval 29 Day) AND '2019-07-27'
group by activity_date;

