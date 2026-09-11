TASK1:

select ename,sal
from emp
where sal = (select max(sal)
             from emp);

TASK2:

select ename,sal
from emp
where sal > (select avg(sal)
             from emp);

TASK3:

select ename,deptno
from emp
where deptno = (select deptno
                from emp
                where ename='SCOTT');

TASK4:

select ename,sal
from emp
where sal = (select min(sal)
             from emp
             group by deptno
             having deptno=30);


TASK5:

select ename,sal
from emp
where sal > ANY(select sal
                from emp
                where deptno=30);

TASK6:

select ename,sal
from emp
where sal > ALL(select sal
                from emp
                where deptno=20);

TASK7:

select ename,job
from emp
where job = (select job
             from emp
             where ename='ALLEN');

TASK8:

select *
from emp e,emp m
where e.mgr=m.empno
AND e.sal<m.sal;

TASK9:

select d.dname
from emp e,dept d
where e.deptno=d.deptno
group by d.dname
having avg(e.sal)>(select avg(sal)
                   from emp);

TASK10:
select ename,sal
from emp
where sal=(select max(sal)
                 from emp
                 where sal < (select max(sal)
                              from emp));

TASK11:

select ename,hiredate
from emp
where hiredate<(select hiredate
				from emp
				where ename='KING')


TASK12:

select ename
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal 
AND s.grade=(select s.grade
             from salgrade s,emp e
             where e.sal
             BETWEEN s.losal AND s.hisal 
             AND ename='SMITH');

TASK13:

select e.ename
from emp e,dept d
where e.deptno=d.deptno
AND d.loc='DALLAS'

TASK14:

select ename,deptno
from emp
where deptno <> ANY(select deptno 
                from emp
                where ename='CLARK');
TASK15:

select ename,sal
from emp
where sal > (select max(sal)
                from emp
                group by deptno
                having deptno=10)
AND sal<(select max(sal)
                from emp
                group by deptno
                having deptno=30);