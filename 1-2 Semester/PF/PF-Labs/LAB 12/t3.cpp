#include<iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;
int length(string s);
bool isequal(int len,string s);
int main() 
{
    string s ;
    cout<<"enter a string"<<endl;
    getline(cin,s);
    int l=length(s);
    bool check=isequal(l,s);
    if(check==true)
    {
    	cout<<"true";
	}
	else
	{
    	cout<<"false";
	}
	
	
}
int length(string s)
{
    int i = 0;
    int count = 0;
    
    while (s[i] != '\0')
    {
        count++;
        i++;
    }	
    return count;
}
bool isequal(int len,string s)
{   bool check =true;
    for(int k=0;k<=len-1;k++)
    {
    	
    	if(s[k]!=s[len-1])
    	{
    	  check= false;
    	  return check;
		  	
		}
		len--;
    	
	}
	return check;
}
