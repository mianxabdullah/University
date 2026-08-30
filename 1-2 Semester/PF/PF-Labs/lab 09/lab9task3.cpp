#include <iostream>
#include <array>
#include <string>
using namespace std;
int main()
{ array<int,5>dis;
  array<int,5>time;
  array<float,5>speed;
  cout<<"enter distances";
  int i=0;
  int j=0;
  int k=0;
  while(i<5)
  {
   cin>>dis[i]; 
   i++;
  }
  cout<<"enter times";
  while(j<5)
  {
   cin>>time[j];
   j++; 
  }
  while(k<5)
  {
   speed[k]=float(dis[k])/float(time[k]); 
   k++;
  }
  int x=0;
  cout<<"distance time speed"<<endl;
  while(x<5)
  { cout<<dis[x]<<"        "<<time[x]<<"     "<<speed[x]<<endl;
    x++;
  }
}