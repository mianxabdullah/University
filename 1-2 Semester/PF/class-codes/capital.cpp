#include<iostream>
#include<string>
using namespace std;
string caps(string str)
{   string s=str;
	for(int i=0;i<s.length();i++)
	{
		if (s[i]==' ')
		{
			s[i+1]=s[i+1]-32;
			
		}
	}
	return s;
}
int main()
{
   string str="i am abdullah ayub";
   cout<<caps(str);	
}