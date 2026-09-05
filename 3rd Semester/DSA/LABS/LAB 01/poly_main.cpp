#include"poly.h"
#include<iostream>
using namespace std;
int main ()
{
    polynomial p(5); 
    p.addTerm(2,0);  
    p.addTerm(3,2);
    p.addTerm(7,3);
    p.addTerm(2,5);
    p.addTerm(9,7);
    p.addTerm(5,9);

    polynomial p2(3);
    p2.addTerm(2,0);
    p2.addTerm(6,2);
    p2.addTerm(4,3);

    polynomial p3(3);
    //p1 = 4x5 + 7x3 - x2 + 9
    p3.addTerm(4,5);
    p3.addTerm(7,3);
    p3.addTerm(-1,2);
    p3.addTerm(9,0);

    cout<<p<<endl<<p2<<endl;
    cout<<"sum: "<<p+p2<<endl;
    cout<<"subtract: "<<p-p2<<endl;

    cout<<"org: "<<p3<<endl;
    cout<<"Derivative:";
    p3.derivative();

    polynomial p4(3);
    //p1 = 4x5 + 7x3 - x2 + 9
    p4.addTerm(-2,1);
    p4.addTerm(21,2);
    p4.addTerm(20,4);

    cout<<endl<<"org: "<< p4<<endl;
    cout<<"Anti Derivative:";
    p4.Antiderivative();

    cout<<endl<<"Polynomial: "<<p<<endl;
    cout<<"Coefficient:"<<p.getCoefficient(3)<<endl;
    cout<<"Degree:"<<p.degree()<<endl;
    cout<<"Solution:"<<p(2)<<endl;

    polynomial a(1);
    a.addTerm(5,5);
    cout<<"add to Coefficient:";
    a.addtoCoefficient(3,5);
    cout<<a;

}