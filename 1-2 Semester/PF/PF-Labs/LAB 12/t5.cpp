#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
struct student
{
	int rollno;
	string name;
	double matric;
	double inter;
};
int main()
{
	student x;
	cout<<"enter roll no "<<endl;
	cin>>x.rollno;
	cout<<"enter name "<<endl;
	cin>>x.name;
	cout<<"enter matric marks "<<endl;
	cin>>x.matric;
	cout<<"enter intermidiate marks "<<endl;
	cin>>x.inter;
	student *p=&x;
	cout<<"roll no is :"<<p->rollno<<endl;
	cout<<"name is :"<<p->name<<endl;
	cout<<"matric marks :"<<p->matric<<endl;
	cout<<"inter marks :"<<p->inter<<endl;
}
	
	
