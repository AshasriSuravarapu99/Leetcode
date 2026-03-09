/* Write your PL/SQL query statement below */
select e1.name as Employee from
Employee e1 CROSS JOIN Employee e2
where e1.managerid = e2.id and e1.salary > e2.salary;