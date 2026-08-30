#include<iostream>
#include<string>

using namespace std;

class matrix33
{
	protected:
		double m[3][3];
	public:
	double getElement(int row, int col)
	{
		return m[row][col];
	}
    void setElement(int row, int col, double val)
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
	void setmatrix(double a[3][3] )	
	{
	  for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	m[i][j]=a[i][j];
		  }	
		}	
	}
	//5
		matrix33(double val1,double val2,double val3,double val4,double val5,double val6,double val7,double val8,double val9)
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
	matrix33(double value)
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
		  	m[i][j]=0;
		  }	
		}	
	}
	//8
	void multiply(int n)
	{
	   for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
		  	m[i][j]=(m[i][j]*n);
		  }	
		}	
	}
	//9
     
	//10
	bool isequal(matrix33 &n)
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
	
	//9
	double det()
	{
		double a,b,c,d,e,f,i,j,k,x,y,z;
		double res=1;
		a=m[0][0];
		b= -m[0][1];
		c=m[0][2];
		
		d=m[1][0];
		e=m[1][1];
		f=m[1][2];
		
		i=m[2][0];
		j=m[2][1];
		k=m[2][2];
		
	
		x=(a*((e*k)-(f*j)));
		y=(b*((d*k)-(f*i)));
		z=(c*((d*j)-(e*i)));
		
		res=a+b+c;
		
		
		return res;
	}
	
		
};
int main()
{
	matrix33 mat;
	matrix33 mat1;
	matrix33 mat2(2);
	matrix33 mat3={1,2,3,4,5,6,7,8,9};
	matrix33 mat4={1,2,3,4,5,6,7,8,9};
	
	
	mat.setElement(0,0,10);
	cout<<mat.getElement(0,0)<<endl<<endl<<endl;
	mat.display();
	cout<<endl<<endl<<endl;
	double arr[3][3]={{0,1,2},{3,4,5},{6,7,8}};
	mat.setmatrix(arr);
	mat.display();
	
	cout<<endl<<endl<<endl;
	mat1.display();
	
	cout<<endl<<endl<<endl;
	mat2.display();
	
	cout<<endl<<endl<<endl;
	mat3.display();
    
    
	cout<<endl<<endl<<endl;
	mat4.multiply(5);
	mat4.display();
	
	
	
	
	cout<<endl<<endl<<endl;
	matrix33 mat6={4,2,3,4,5,6,7,8,9};
	cout<<endl<<mat3.isequal(mat6);
	
	
	cout<<endl<<endl<<endl;
	matrix33 matrix={4,2,3,4,5,6,7,8,9};
	matrix.display();
	cout<<endl;
	cout<<matrix.det();
	
	
}