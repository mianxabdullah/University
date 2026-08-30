#include <iostream>
#include <string>
using namespace std;
class X
{
public:
string data = "X";
X(){cout << "X born\n";}
~X(){cout << "X died\n";}
void showData(){cout << data << '\n';}
};
class Y
{
public:
char data = 'Y';
Y(){cout << "Y born\n";}
~Y(){cout << "Y died\n";}
void showData(){cout << data << '\n';}
};
class A
{
public:
double data = 777.888;
Y y;
A(){cout << "A born\n";}
~A(){cout << "A died\n";}
void showData(){cout << data << '\n';}
};
class B : public A
{
public:
int data = 420;
Y y;
X *xp; // no object created
B(){cout << "B born\n";}
~B(){cout << "B died\n";}
void showData(){cout << data << '\n';
/*A::y.data = char(153);
cout << A::y.data << '\n';*/}
};
class C : public B
{
public:
bool data = false;
Y y;
C(){cout << "C born\n";}
~C(){cout << "C died\n";}
void showData(){cout << data << '\n';
/*cout << A::y.data << '\n';*/}
};
int main()
{
X *xp; // no object created
cout << "---------------\n";
X x; x.showData();
cout << "---------------\n";
Y y; y.showData();
cout << "---------------\n";
A a; a.showData();
cout << "---------------\n";
B b; b.showData();
cout << "---------------\n";
C c; c.showData();
cout << "---------------\n";
return 0;
}