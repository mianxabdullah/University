#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct vector
{
	int magnitude (int x,int y)
	{
		return sqrt(x*x+y*y);
	}
};
int main()
{
	vector VA;
	cout<<VA.magnitude(3,4);
}