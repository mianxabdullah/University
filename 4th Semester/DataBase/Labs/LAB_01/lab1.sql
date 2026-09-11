Task 1:
select *
from emp;

Task 2:
select ename,job,sal
from emp;

Task 3:
select *
from emp
where job='CLERK';

Task 4:
select *
from emp
where sal>3000;

Task 5:
select *
from emp
where sal<1500;

Task 6:
select *
from emp
where deptno=10;

Task 7:
select *
from emp
where deptno=20
AND sal>2000;

Task 8:
select *
from emp
where sal>2000
AND sal<4000;


Task 9:
select distinct job
from emp;

Task 10:
select ename,sal
from emp ;

Task 11:
select ename||'-'||job as Employee_info
from emp ;

Task 12:
select ename,sal,sal*12 as Annual_Salary
from emp;

Task 13:
select distinct dname
from dept;

Task 14:
select dname,loc
from dept
where loc='NEW YORK';

Task 15:
select *
from salgrade
where losal>2000;




