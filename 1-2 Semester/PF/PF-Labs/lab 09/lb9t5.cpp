#include <iostream>
#include <array>
#include <string>
using namespace std;
const float PI=3.14;
int main()
{ int radius;
  cout<<"enter radius of a circle"<<endl;
  cin>>radius;
  float area=PI*radius*radius;
  cout<<"area of circle is :"<<area;
}