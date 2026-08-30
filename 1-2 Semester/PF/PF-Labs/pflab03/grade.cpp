#include<iostream>
#include<string>
using namespace std;
char grade(int marks)
{
    char grad;
    if(marks>=80)
    {
        grad='A';
    }
    else if(marks>=50)
    {
        grad='B';
    }
    else if(marks<50)
    {
        grad='F';
    }
    return grad;
}
int main()
{
    int m;
    cout<<"Marks:";
    cin>>m;
    cout<<"The grade is:"<<grade(m)<<endl;
    return 0;
}