#include<iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;
int length(string s);
int main() 
{
    string s ;
    cout<<"enter a string"<<endl;
    getline(cin,s);
    int l=length(s);
    cout<<l;
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
