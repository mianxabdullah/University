#include<iostream>
#include<string>

using namespace std;
template<typename t>
class matrix33
{
	protected:
		t m[3][3];
	public:
	t getElement(t row, t col)
	{
		return m[row][col];
	}
    void setElement(t row, t col, t val)
	{
		m[row][col]=val;
	}
	void display()
	{
		for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	cout<<m[i][j]<<" ";
		  }	
		  cout<<endl;
		}
	}
	double setmatrix(t a[3][3] )	
	{
	  for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	m[i][j]=a[i][j];
		  }	
		}	
	}
	//5 constructor
		matrix33(t val1,t val2,t val3,t val4,t val5,t val6,t val7,t val8,t val9)
	{
	 
		  	m[0][0]=val1;
		 	m[0][1]=val2;
		 	m[0][2]=val3;
		 	m[1][0]=val4;
		 	m[1][1]=val5;
		 	m[1][2]=val6;
		 	m[2][0]=val7;
		 	m[2][1]=val8;
		 	m[2][2]=val9;
	}
    
	
	
	
	//6
	matrix33(t value)
	{
	  for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	m[i][j]=value;
		  }	
		}	
	}
	
	//7
	matrix33()
	{
	  for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	m[i][j]=t();
		  }	
		}	
	}
	//8
	matrix33 multiply(t n)
	{  matrix33 _m;
	   t val;
	   for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	val=(m[i][j]*n);
		  	_m.setElement(i,j,val);
		  }	
		}
		return _m;	
	}
	//9
	t determinent()
	{
	t a, b, c, d,e,f,i,j,k;
    t one, two , three;
    t result = 1;
    a = m[0][0];
    b = -m[0][1];
    c = m[0][2];
    d = m[1][0];
    e = m[1][1];
    f = m[1][2];
    i = m[2][0];
    j = m[2][1];
    k = m[2][2];
    one = (a * ((e*k) - (f*j)));
    two  = (b* ((d*k) - (f*i)));
    three = (c* ((d*j) - (e*i)));
    result = one + two + three;
    return result;
	}
	//10
	bool isequal(matrix33<t> &n)
	{   bool res=true;
		 for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	if(m[i][j] != n.getElement(i,j))
		  	{
		  	  res=false;	
			}
		  }	
		}
		return res;
	}
	
		
};
int main()
{
	matrix33<int> mat;
	matrix33<int> mat1;
	matrix33<int> mat2(2);
	matrix33<int> mat3={1,2,3,4,5,6,7,8,9};
	matrix33<int> mat4={1,2,3,4,5,6,7,8,9};
	
	
	mat.setElement(0,0,10);
	cout<<mat.getElement(0,0)<<endl<<endl<<endl;
	mat.display();
	cout<<endl<<endl<<endl;
	int arr[3][3]={{0,1,2},{3,4,5},{6,7,8}};
	mat.setmatrix(arr);
	mat.display();
	
	cout<<endl<<endl<<endl;
	mat1.display();
	
	cout<<endl<<endl<<endl;
	mat2.display();
	
	cout<<endl<<endl<<endl;
	mat3.display();
    
    
	cout<<endl<<endl<<endl;
    matrix33<int> mul=mat4.multiply(5);
    cout<<endl;
	mul.display();
	
	cout<<endl<<endl<<endl;
	matrix33<int> mat5={4,2,3,4,5,6,7,8,9};
	mat5.display();
	cout<<mat5.determinent();
	
	
	cout<<endl<<endl<<endl;
	matrix33<int> mat6={4,2,3,4,5,6,7,8,9};
	cout<<endl<<mat5.isequal(mat6);
	
	
	
}