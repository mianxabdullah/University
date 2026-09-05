#include<iostream>
#include<vector>
using namespace std;
bool linearSearch(int arr[],int n,int tar)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==tar)
        {
            return true;
        }
    }
    return false;
}

//Binary search only valid for sorted arrays either ascending or descending
/*
1. find mid (mid = (start+end)/2) where start is 0 and end is n-1  
   b) optimized formula mid = st + (end-st)/2;
2. if target>mid search in 2nd half (mid+1 to end)
3. if target<mid search in first half (start to mid-1)
4. if target == mid ans=mid
*/
bool binarySearch(vector<int>arr,int tar)
{
    int start=0;
    int end=arr.size()-1;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(arr[mid]>tar)
        {
            end=mid-1;
        }

        else if(arr[mid]<tar)
        {
            start=mid+1;
        }

        else
        {
            return true; //return mid if you want to return index of key
        }
    }

    return false; 
}
int RecursiveBinSearch(vector<int>arr,int tar,int st,int end)
{
    if(st<=end)
    {
        int mid = st + (end-st)/2;
        if(arr[mid]>tar)
        {
            RecursiveBinSearch(arr,tar,st,mid-1) ;  
        }

        else if(arr[mid]<tar)
        {
            RecursiveBinSearch(arr,tar,mid+1,end);
        }

        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int>arr={1,22,33,55,67,111};
    int tar1 = 67;
    if(binarySearch(arr,tar1))
    cout<<"True";
}