#include<iostream>
using namespace std;
#include "ratio.h"
int main()
{   
    rational r(1,2);
    cout<<"rational number by constructor : ";
    r.display();
    cout<<endl; 
        
    rational r1;
    r1.setNum(5);
    r1.setDen(7);
    cout<<"rational number by setting num and den seperately : ";
    r1.display();
    
    cout<<endl;
    int a=r1.getNum();
    int b=r1.getDen();
    cout<<a<<"/"<<b;
    
    cout<<endl;
    rational r2;
    r2.setRational(3,4);
    cout<<"rational number by setRational :";
    r2.display();
    
    cout<<endl;
    rational r3(7,8);
    cout<<"additive inverse of ";
	r3.display();
	cout<<" is : ";
    r3.adinverse().display();
    cout<<endl;
    
    rational r4(8,9);
    cout<<"reciprocal of ";
    r4.display();
    cout<<" is : ";
    r4.reciprocal().display();
    cout<<endl;
    
    rational r5(3,4);
    rational r6(7,4);
    cout<<"Addition of ";
    r5.display();
    cout<<" and ";
    r6.display();
    cout<<" is : ";
    r5.add(r6).display();
    cout<<endl;
    
    
    cout<<"multiplication of ";
    r5.display();
    cout<<" and ";
    r6.display();
    cout<<" is : ";
    r5.multiply(r6).display();
    cout<<endl;
    
    rational r7(20,2);
    cout<<"addition of an integer 5 with ";
    r7.display();
    cout<<" is : ";
    r7.addint(5).display();
	
	cout<<endl;
	rational r8(20,4);
	cout<<"simplified form of ";
	r8.display();
	cout<<" is : ";
	r8.simplify().display();
	cout<<endl;
	
	rational r9(2,4);
	rational r10(1,2);
	if (r9.isequal(r10)) 
	{
        cout << "The fractions are equal!" << endl;
    } 
	else 
	{
        cout << "The fractions are not equal!" << endl;
    }
	//cout<<"isEqual : "<<r9.isequal(r10);
	//r9.isequal(r10);
	
	
	cout<<endl;
	
	rational r11(8,7);
	rational r12(7,8);
	if (r11.isless(r12)) 
	{
        cout << "the fraction on left is less" << endl;
    } 
	else 
	{
        cout << "the fraction on right is less" << endl;
    }
	
    cout<<endl;
	
	rational r13(8,7);
	rational r14(7,8);
	if (r13.isgreater(r14)) 
	{
        cout << "the fraction on left is greater" << endl;
    } 
	else 
	{
        cout << "the fraction on left is not greater" << endl;
    }
}
