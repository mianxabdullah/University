#ifndef studManage
#define studManage

#include<iostream>
using namespace std;
class studentManagement
{
	protected:
		string name;
		string rollNo;
		float cgpa;
	public:
		studentManagement();
		studentManagement(string, string, float);
		setDetails(string ,string ,float);
		void displayDetails();
		bool isOnList();
		
};

#endif