select product_id,10 as price 
FROM Products
group by product_id
having MIN(change_date)>'2019-08-16'

UNION ALL 

select product_id,new_price as price
from Products x
where (x.product_id,x.change_date) IN (
    SELECT 
    product_id,
    max(change_date)
    from  Products t
    where t.change_date<= '2019-08-16'
    group by 
    t.product_id
)

