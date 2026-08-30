#include <iostream>
#include <array>
#include <string>
using namespace std;
int main()
{
  int num=0,alpha=0,special=0;
  array<char,20>ar;
  int i=0;
  cout<<"enter numbers alphabets or special characters";
  while(i<20)
  { cin>>ar[i];
    if(ar[i]>='A'&& ar[i]<='z')
    {
	 alpha++;
	}
	else if(ar[i]>='0'&& ar[i]<='9')
	{
		num++;
	}
	else
	{
	  special++;
	}
    i++;
  }
  cout<<"alphabets are:"<<alpha<<endl;
  cout<<"numbers are:"<<num<<endl;
  cout<<"specials are:"<<special<<endl;
  
}