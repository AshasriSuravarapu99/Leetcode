
with cte as(select e.name as Employee, d.name as Department, e.salary as Salary,
rank() over(partition by d.id order by e.salary DESC) as rnk from
employee e
join
department d
on e.departmentId = d.id)
select Department,Employee, Salary from cte where rnk = 1; 