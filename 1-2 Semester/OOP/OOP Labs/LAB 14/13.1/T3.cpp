#include<iostream>
using namespace std;
int main()
{
    double *v[25];
    for(int i=0;i<25;i++)
    {
        v[i]=new double[i+1];
    }
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<=i;j++)
        {
            v[i][j]=rand()%8+2;
        }
    }

    cout << "Triangular 2D Array: "<<endl;
    for (int i = 0; i < 25; i++) 
    {
        for (int j = 0; j<=i; j++) 
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0;i<25;i++)
    {
        delete[] v[i];
    }
}