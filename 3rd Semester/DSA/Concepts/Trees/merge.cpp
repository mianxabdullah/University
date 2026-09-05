#include<iostream>
using namespace std;
void merge(int a[],int b[],int n , int m,int c[])
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;   
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        c[k]=b[j];
        j++;
        k++;
    }
}
void merge(int a[], int l, int r, int p)
{
    int n1 = r - l + 1;
    int n2 = p - r;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[r + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];
}
void mergeSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);

        merge(arr,p,q,r);
    }
}

int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int j=p;
    int i=p-1;
    while(j<=r-1)
    {
        if(arr[j]<x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main()
{
    int x[5]={2,4,63,69,77};
    int y[3]={22,33,44};
    int z[8];
    merge(x,y,5,3,z);
    for(int i = 0; i < 8; i++)
    cout << z[i] << " ";
    cout << endl;

    int n[11]={5,8,9,10,12,3,6,11,13,15,17};
    merge(n,0,4,10);
    for(int i = 0; i < 11; i++)
    cout << n[i] << " ";
    cout << endl;

    int a[]={6,9,3,2,8,11,10,7,4,6};
    mergeSort(a,0,9);
    cout<<"MergeSort:"<<endl;
    for(int i = 0; i < 10; i++)
    cout << a[i] << " ";
    cout << endl;

    int ar[]={6,9,3,2,8,11,10,7,4,55,1,303,9};
    quickSort(ar,0,12);
    cout<<"QuickSort:"<<endl;
    for(int i = 0; i < 13; i++)
    cout << ar[i] << " ";
    cout << endl;

}