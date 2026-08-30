#include <iostream>
#include <array>
using namespace std;
int lastIndex (array<int,100>ar,int n,int a)
{ int ind=0;
  int i=0;
  while(i<n)
  {
    if(ar[i]==a)
     { 
         ind=i;
         
     }
     i++;
  }
  return ind;
} 
int main() {
    array<int,100>arr={1,2,6,7,9,1,7,8,1};
    int n=9;
    int a=1;
    cout<<lastIndex(arr,n,a);
}