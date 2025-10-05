SELECT q.person_name
FROM Queue q
WHERE 1000 >= (
    SELECT SUM(t.weight)
    FROM Queue t
    WHERE t.turn <= q.turn
)
ORDER BY q.turn DESC
LIMIT 1;
