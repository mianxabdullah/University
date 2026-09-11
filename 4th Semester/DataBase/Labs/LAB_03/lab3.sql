TASK1:
select ename,job,sal
from emp
where deptno=30;

TASK2:
select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno;

TASK3:
select e.ename,e.sal,s.grade
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal ;

TASK4:
select e.ename,e.job,d.dname
from emp e,dept d
where e.deptno=d.deptno
AND (e.job='CLERK' OR e.job='ANALYST');

TASK5:
select e.ename emloyee_name,m.empno manager_id,m.ename manager_name
from emp e,emp m
where e.empno=m.mgr;

TASK6:
select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno (+);

TASK7:
select deptno,sum(sal)
from emp 
group by deptno;

TASK8:
select max(sal),min(sal),avg(sal)
from emp ;

TASK9:
select deptno,count(empno)
from emp 
group by deptno;

TASK10:
select deptno,max(sal)
from emp 
group by deptno;

TASK11:
select m.ename,count(e.empno)
from emp e,emp m
where e.mgr=m.empno
group by m.ename;

TASK12:
select e.ename,e.sal,s.grade
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal ;

TASK13:
select d.dname,avg(e.sal)
from emp e,dept d
where e.deptno=d.deptno 
group by d.dname;

TASK14:
select d.dname,sum(e.sal)
from emp e,dept d
where e.deptno=d.deptno 
group by d.dname;

TASK15:
select e.ename,e.sal,s.grade
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal 
AND s.grade=3;


