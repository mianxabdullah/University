#include <iostream>
#include <array>
#include <string>
using namespace std;
void printMonths(array<string,12>ar)
{ int j=0;
  while(j<12)
  { 
    cout<<ar[j]<<endl;
    j++;
  }
}
int main()
{ 
  array<string,12>ar;
  cout<<"enter names of months one by one "<<endl;
  int i=0;
  while(i<12)
  {
    cin>>ar[i];
    i++;
  }
  cout<<"entered months are:";
  printMonths(ar);
}