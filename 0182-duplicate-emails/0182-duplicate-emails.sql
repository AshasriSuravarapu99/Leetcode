/* Write your PL/SQL query statement below */
with dummy as (
    select count(*) as count,email from Person group by email
)
select email from dummy where count > 1;