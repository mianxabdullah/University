#include<iostream>
using namespace std;
int main()
{
    int a[25],n;
    cout<<"Enter values of array you want to enter (less than 25):";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value no."<<i+1<<endl;
        cin>>a[i];
    }
    for(int i=0;i<n;i=i+2)
    {
        if(a[i]<=a[i+1])
        {
            if(i==n-1)
            {
                if(a[i]<a[0])
                {
                    cout<<"("<<a[i]<<","<<a[0]<<")"<<endl;
                }
                else
                {
                    cout<<"("<<a[0]<<","<<a[i]<<")"<<endl; 
                }
                exit(5);
                return 5;
            }
           cout<<"("<<a[i]<<","<<a[i+1]<<")"<<endl;
        }
        else
        {
            cout<<"("<<a[i+1]<<","<<a[i]<<")"<<endl;
        }
    }
}