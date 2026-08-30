#include<iostream>
using namespace std;
void sortArray(int *arr, int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
float avg(int *arr,int siz)
{
    float sum=0.0;
    for(int i=0;i<=siz-1;i++) sum+=arr[i];
    float avg = sum/siz;
    return avg;
}
int main()
{
    int size;
    cout<<"Enter no of test scores"<<endl;
    cin>>size;
    int *array = new int[size];
    for(int i=0;i<=size-1;i++)
    {
        cout<<"enter test score no "<<i+1<<" : ";
        cin>>array[i];
        cout<<endl;
    }
    sortArray(array,size);
    float average = avg(array,size);
    cout<<"TEST SCORES      AVERAGE"<<endl;
    for(int i=0;i<=size-1;i++)
    {
        cout<<array[i]<<"               "<<average<<endl;
    }
    delete[] array;
}