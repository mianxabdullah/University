Task 1:
select ename,sal as "Original salary",sal*1.15 as "New Salary"
from emp;

Task 2:
select ename,round(sal*12) as "Annual salary"
from emp;

Task 3:
select ename,job,length(job)
from emp;

Task 4:
select ename,substr(ename,length(ename)-1,length(ename))
from emp;

Task 5:
select ename,LPAD(sal,10,'*')
from emp;

Task 6:
select ename,decode(sign(sal-7000)
                    ,0,"HIGH"
                    ,1,"HIGH"
                    ,-1,decode(sign(sal-4000),
                                0,"MEDIUM",
                                1,"MEDIUM",
                                -1,"LOW")
                        ," ") AS salary
from emp;

Task 7:
select ename,decode(comm,
                    ,NULL,"no commision"
                        ,comm) AS commision
from emp;

Task 8:
select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno
AND d.dname is not null;

Task 9:
select e.ename,d.dname,d.loc,e.sal
from emp e,dept d
where e.deptno=d.deptno
AND e.sal>3000;

Task 10:
select e.ename,d.dname,d.loc
from emp e,dept d
where e.deptno=d.deptno
AND d.loc ='DALLAS';

Task 11:
select d.dname,sum(e.sal)
from emp e,dept d
where e.deptno=d.deptno
group by d.dname
Order by sum(e.sal) desc;

Task 12:
select d.deptno,avg(e.sal)
from emp e,dept d
where e.deptno=d.deptno
group by d.deptno
having count(ename) >3;

Task 13:
select e.ename , m.ename
from emp e,emp m
where e.mgr=m.empno;

Task 14:
select ename ,sal
from emp 
where sal>(select avg(sal)
           from emp
           where deptno=20);

Task 15:
select e.ename 
from emp e
where sal=(select max(m.sal)
           from emp m
           where e.deptno=m.deptno
           group by m.deptno);

Task 16:
select ename ,deptno
from emp 
where deptno=(select deptno
              from emp
              where ename='ALLEN');
			  
Task 17:
select ename ,sal
from emp 
where sal>ANY(select sal
              from emp
              where deptno=30);

Task 18:
select ename ,sal
from emp 
where sal<ALL(select sal
              from emp
              where deptno=10);

Task 19:
select ename,last_day(hiredate)
from emp ;

Task 20:
select ename,add_months(hiredate,6)
from emp ;







select e.ename 
from emp e
where sal>(select avg(m.sal)
           from emp m
           where e.hiredate>m.hiredate);