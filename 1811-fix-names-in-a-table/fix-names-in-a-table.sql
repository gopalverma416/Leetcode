SELECT user_id,CONCAT(UPPER(left(name,1)), LOWER(substring(name,2))) as name
from Users
ORDER BY user_id ASC;