#include<iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;
int length(string s);
void rev(int len,string s);
int main() 
{
    string s ;
    cout<<"enter a string"<<endl;
    getline(cin,s);
    int l=length(s);
    rev(l,s);
    
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
void rev(int len,string s)
{
	for(int x=len;x>=0;x--)
    {
    	cout<<s[x];
	}
}
