UPDATE salary
SET sex=CASE 
WHEN SEX='m' then 'f'
when sex='f' then 'm'
END; 