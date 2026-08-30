#include <iostream>
#include <array>
using namespace std;
int maxIndex (array<int,100>ar,int n)
{ int ind=0;
  int i=0;
  while(i<n)
  {
    if(ar[i]>ar[i+1])
     { 
         ind=i;
     }
     i++;
  }
  return ind;
} 
int main() {
    array<int,100>arr={1,2,6,7,18};
    int n=5;
    cout<<maxIndex(arr,n);
}