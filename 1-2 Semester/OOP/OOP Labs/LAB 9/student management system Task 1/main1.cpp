#include"sms.h"
#include<iostream>
using namespace std;
int main()
{
	studentManagement s[3];
	for(int i=0;i<3;i++)
	{
		string nam,roll;
		float gpa;
		cout<<"Enter the name,rollno,cgpa os student "<<i+1<<" : ";
		cin>>nam>>roll>>gpa;
		s[i].setDetails(nam,roll,gpa);
	}
	for(int j=0;j<3;j++)
	{
		s[j].displayDetails();
		if(s[j].isOnList())
		{
			cout<<"the student is on dean's honour list";
		}
		else
		{
			cout<<" the student is not on dean's honour list" ;
		}
		cout<<endl;
    }
}