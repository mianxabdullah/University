#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<right<<setw(20)<<"hello"<<endl;
	cout<<left<<setw(20)<<"hello"<<endl;
	cout<<internal<<setw(20)<<"hello"<<endl;
	
	
	// Custom manipulator for dollar formatting
ostream& dollar(ostream& os) {
    os << "$" << fixed << setprecision(2);
    return os;
}

cout << dollar << 24.5;  // Outputs: $24.50

}