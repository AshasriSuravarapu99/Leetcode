/* Write your PL/SQL query statement below */
with cte as(
    select count(*) as cnt,customer_number as id from orders 
    group by customer_number;
)
select id as customer_number from cte
where cnt = (select max(cnt) from cte);