#include"sms.h"
#include<iostream>
using namespace std;

studentManagement::studentManagement()
	{
		name=" ";
		rollNo=" ";
		cgpa=0.0;
	}

studentManagement::studentManagement(string n,string r,float gpa) : name(n),rollNo(r),cgpa(gpa)
	{}
		
		
studentManagement::setDetails(string n,string r,float c)
{
	name=n;
	rollNo=r;
	cgpa=c;
}

void studentManagement::displayDetails()
{
	cout<<"Name : "<<name<<endl;
	cout<<"RollNO : "<<rollNo<<endl;
	cout<<"CGPA : "<<cgpa<<endl;
}

bool studentManagement::isOnList()
{
	return (cgpa>=3.5);
}