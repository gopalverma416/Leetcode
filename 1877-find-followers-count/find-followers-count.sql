SELECT user_id ,COUNT(*) as  followers_count
FROM Followers
group by user_id 
order by user_id ASC;
