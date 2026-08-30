#include<iostream>
#include<iomanip>
using namespace std;
struct teacher 
{
	string name,course,dpt;
	int rank;
};
int main()
{
	teacher* a[4];
	for(int i=0;i<5;i++)
	{
		a[i]= new teacher;
	}
	for(int i=0;i<5;i++)
	{
		cout<<"enter data for teacher "<<i+1<<": "<<endl;
		cout << "Name: ";
        getline(cin, a[i]->name);
        cout << "Course: ";
        getline(cin, a[i]->course);
        cout << "Department: ";
        getline(cin, a[i]->dpt);
        cout << "Rank: ";
        cin >> a[i]->rank;
        cin.ignore();
    }
    cout<<endl;
    cout<<"Sr.No"<<setw(15)<<"Name"<<setw(15)<<"Course"<<setw(15)<<"Department"<<setw(15)<<"Rank"<<endl;
    for(int i=0;i<5;i++)
	{
		cout<<<<i+1<<setw(15)<<a[i]->name<<setw(15)<<a[i]->course<<setw(15)<<a[i]->dpt<<setw(15)<<a[i]->rank;
		cout<<endl;
	}
	for(int i=0;i<5;i++)
	{
		delete a[i];
	}
	

	
}