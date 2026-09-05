#include <iostream>
using namespace std;
class Matrix
{
protected:
    int** data;
    int row;
    int col;
public:
    Matrix(int r=0,int c=0)
    {
        row=r;
        col=c;
        if(row>0 && col>0)
        {
            data=new int *[r];
            
            for(int i=0;i<row;i++)
            {
                data[i]=new int[col];
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    data[i][j]=0;
                }
            }
        }
        else
        data=nullptr;

    }
    ~Matrix()
    {
        for(int i=0;i<row;i++)
        {
            delete[] data[i];
        }   
        delete[] data;
    }
    void setValue(int r,int c,int val)
    {
        data[r][c]=val;
    }
    int getValue(int r,int c) const
    {
        return data[r][c];
    }
    void Display() const
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int getRows() const 
    { 
        return row; 
    }
    int getCols() const 
    { 
        return col; 
    }

    int* operator[](int r)
    {
        return data[r];
    }
};
class SparseMatrix
{
protected:
    int nonzeros;
    int** smat;
public:
    SparseMatrix(int n=0)
    {
        nonzeros=n;
        if(nonzeros>0)
        {
            smat=new int*[nonzeros];
            for(int i=0;i<nonzeros;i++)
            {
                smat[i]=new int[3];
            }
        }
        else
        {
            smat=nullptr;
        }
    }

    SparseMatrix(const SparseMatrix& other) 
    {
        nonzeros = other.nonzeros;
        if (nonzeros > 0) 
        {
            smat = new int*[nonzeros];
            for (int i = 0; i < nonzeros; i++) 
            {
                smat[i] = new int[3];
                for (int j = 0; j < 3; j++) 
                {
                smat[i][j] = other.smat[i][j];
                }
            }
        } 
        else 
        {
            smat = nullptr;
        }
}

    SparseMatrix& operator=(const SparseMatrix& other) 
    {
        if (this != &other) 
        {
            for (int i = 0; i < nonzeros; i++)  
            { 
                delete[] smat[i];
            }
            delete[] smat;
            nonzeros = other.nonzeros;
            if (nonzeros > 0) 
            {
                smat = new int*[nonzeros];
                for (int i = 0; i < nonzeros; i++) 
                {
                    smat[i] = new int[3];
                    for (int j = 0; j < 3; j++) 
                    {
                        smat[i][j] = other.smat[i][j];
                    }
                }
            } 
            else   
            {
                smat = nullptr;
            }
        }
        return *this;
    }
    ~SparseMatrix()
    {
        for(int i=0;i<nonzeros;i++)
        {
            delete[] smat[i];
        }   
        delete[] smat;
    }
    void ReadSparseMat(const Matrix& m)
    {
        int count=0;
        for(int i=0;i<m.getRows();i++)
        {
            for(int j=0;j<m.getCols();j++)
            {
                if(m.getValue(i,j)!=0)
                {
                    count++;
                }
            }
        }
        int temp=nonzeros;
        nonzeros=count;
        if(smat)
        {
            for(int i=0;i<temp;i++)
            {
                delete[] smat[i];
            }      
            delete[] smat;
        }

        smat=new int*[nonzeros];
        for(int i=0;i<nonzeros;i++)
        {
            smat[i]=new int[3];
        }

        int k=0;
        for(int i=0;i<m.getRows();i++)
        {
            for(int j=0;j<m.getCols();j++)
            {
                int val=m.getValue(i,j);
                if(val != 0)
                {
                    smat[k][0]=i;
                    smat[k][1]=j;
                    smat[k][2]=val;
                    k++;
                }
            }
        }
    }

    SparseMatrix AddSparseMat(const SparseMatrix& b)
    {
        int total= nonzeros+b.nonzeros;
        SparseMatrix res(total);
        int k=0;
        for(int i=0;i<nonzeros;i++)
        {
            res.smat[k][0]=smat[i][0];
            res.smat[k][1]=smat[i][1];
            res.smat[k][2]=smat[i][2];
            k++;
        }
        for(int i=0;i<b.nonzeros;i++)
        {   
            bool found=false;
            for(int j=0;j<k;j++)
            {
                if(res.smat[j][0]==b.smat[i][0] && res.smat[j][1]==b.smat[i][1])
                {
                    res.smat[j][2]+=b.smat[i][2];
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                res.smat[k][0]=b.smat[i][0];
                res.smat[k][1]=b.smat[i][1];
                res.smat[k][2]=b.smat[i][2];
                k++;
            }
        }
        res.nonzeros=k;
        return res;
    }

    void Disp() const
    {
        cout << "Row Col Val\n";
        for (int i = 0; i < nonzeros; i++) 
        {
            cout << smat[i][0] << "   "<< smat[i][1] << "   "<< smat[i][2] << endl;
        }
    }
        

};

int main()
{
    Matrix m(3,3);
    m[0][0]=1;
    m[1][1]=2;
    m[2][2]=3;
    cout<<"Original Matrix"<<endl;
    m.Display();
    SparseMatrix S;
    S.ReadSparseMat(m);
    cout << "\nSparse Matrix:\n";
    S.Disp();

    Matrix A(3,3), B(3,3);
    A[0][0] = 1; A[1][1] = 2; A[2][2] = 3;
    B[0][0] = 4; B[1][1] = 5;

    SparseMatrix SA, SB;
    SA.ReadSparseMat(A);
    SB.ReadSparseMat(B);

    cout << "A in sparse:\n"; SA.Disp();
    cout << "B in sparse:\n"; SB.Disp();

    SparseMatrix C = SA.AddSparseMat(SB);
    cout << "Sum in sparse:\n"; C.Disp();
}
