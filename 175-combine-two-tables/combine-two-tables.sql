SELECT
Person.firstName,
Person.lastName,
Address.city,
Address.state
From
person
LEFT JOIN
Address
ON
Person.personId= Address.personId;
