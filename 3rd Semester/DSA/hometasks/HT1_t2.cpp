#include <iostream>
using namespace std;
class array
{
    protected:
    int* d2;
    int row,col;
    public:
    array(int r=2,int c=2)
    {
        d2 = new int [r*c];
        row=r;
        col=c;
    }
    array(const array& rhs)
    {
        row=rhs.row;
        col=rhs.col;
        d2=new int[row*col];
        for(int i=0;i<row*col;i++)
        {
            d2[i]=rhs.d2[i];
        }
    }
    ~array()
    {
        delete[] d2;
    }
    int getIndexValue (int i,int j)
    {
        return d2[i+j*row];
    }
    void setIndexValue (int i,int j,int val)
    {
        d2[i+j*row]=val;
    }
    void printArray ()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<d2[i+j*row]<<" ";
            }
            cout<<endl;
        }
    }
    int addressOfIndex (int i,int j,int StartIndex)
    {
        int addr = StartIndex + (i+j*row) * sizeof(int);
        return addr;
    }
    array operator+(const array& rhs) const
    {
        if(row!=rhs.row ||col!=rhs.col)
        {
            throw runtime_error("dimensions should match for addition");
        }
        array res(row,col);
        for(int i=0; i<row*col;i++)
        {
            res.d2[i]=d2[i]+rhs.d2[i];
        }
        return res;
    }
    void printSubArray (int r1,int r2,int c1,int c2)
    {
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                cout<<d2[i+j*row]<<" ";
            }
            cout<<endl;
        }
    }
    void clear(int r1, int r2, int c1, int c2)
    {
        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                d2[i + j * row] = 0;  
            }
        }
    }

};
int main()
{
    array(3,3);
}