#include <iostream>
#include <array>
using namespace std;
int notAscend (array<int,100>ar,int n)
{ int index=0;
  int i=0;
  while(i<n)
  {
    if(ar[i]> ar[i+1])
     { 
         index=i+1;
         return index;
     }
     i++;
  }
  
} 
int main() {
    array<int,100>arr={1,2,67,599,9,8};
    int n=6;
    cout<<notAscend(arr,n);
}