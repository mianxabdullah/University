Task1:

select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno;

select e.ename,d.dname
from emp e,dept d
where e.deptno= d.deptno (+);

Task2:

select e.ename,d.dname
from emp e,dept d;

Task3:

select e.ename,e.sal,e.sal*12 "AnnualSalary"
from emp e;

Task4:

select initcap(ename)
from emp ;

Task5:

select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno
AND d.loc='NEW YORK';

Task6:

select e.ename,s.grade
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal ;

Task7:
select ename,
decode(sal>3000,'HIGH','NORMAL') 
as status
from emp ;

Task8:

select ename,
decode(comm='NULL',0,comm) 
comm
from emp ;

Task9:

select e.ename,e.job,d.dname
from emp e,dept d
where e.deptno=d.deptno
AND e.job='CLERK'
AND d.deptno=10;

Task10:

select distinct loc
from dept ;

Task11:

select ename,mgr
from emp
where mgr IS NOT NULL;

Task12:

select e.ename,s.grade
from salgrade s,emp e
where e.sal
BETWEEN s.losal AND s.hisal 
AND e.deptno=20;

Task13:

select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno;

Task14:

select ename,trunc(sal,1)
from emp e;

Task15:

select e.ename,d.dname
from emp e,dept d
where e.deptno=d.deptno
AND e.sal>2500
AND d.loc='DALLAS';



