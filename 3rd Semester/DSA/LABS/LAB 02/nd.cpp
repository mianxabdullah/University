#include <iostream>
using namespace std;
class NdArray
{
protected:
    int* nd;
    int s;
    int *dim;
public:
    NdArray(int n,int arr[])
    {
        int totalind=1;
        s=n;
        dim=new int[s];
        for(int i=0;i<s;i++)
        {
            dim[i]=arr[i];
            totalind*=arr[i];

        }
        nd=new int[totalind];
        for(int x=0;x<totalind;x++)
        {
            nd[x]=0;
        }
    }
    int calculateIndex(int set[])
    {
        int linearInd;
        int a=0;
        for(int i=0;i<s;i++)
        {
            linearInd=set[i];
            for(int j=i;j<s-1;j++)
            {
                linearInd*=dim[j+1];
            }
            a+=linearInd;
        }
        return a;
    }
    void setValue( int set[] ,int val)
    {
        int index=calculateIndex(set);
        nd[index]=val;
    }
    int getValue(int set[])
    {
        int index=calculateIndex(set);
        return nd[index];
    } 
    bool isvalidInd(int set [])
    {
        int a=calculateIndex(set);
        int b=calculateIndex(dim);
        if(a>0 && a<b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{

    int dimsize[3]={2,3,5}; 
    NdArray arr(3, dimsize); 
    int indexset[3]={1,2,4}; 
    cout<<endl<<"calculated index:"<<arr.calculateIndex( indexset )<<endl; 
    arr.setValue( indexset , 69); 
    cout<<"value:"<<arr.getValue(indexset)<<endl;
    cout<<"Isvalid:"<<arr.isvalidInd(indexset)<<endl;
    int indexset2[3]={5,2,4};
    cout<<"Isvalid:"<<arr.isvalidInd(indexset2)<<endl;

}