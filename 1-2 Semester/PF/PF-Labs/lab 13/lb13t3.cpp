#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
  int ar[5]={15,7,31,1,-2};
  for(int i=0;i<5;i++)
  {
    cout<<ar[i]<<" ";	
  }
  char* c;
  c= (char*)ar;
   for(int j=0;j<19;j++)
  {
    cout<<c[j]<<endl;	
  }  
}