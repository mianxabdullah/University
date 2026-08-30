#include<iostream>
#include<array>
using namespace std;
class bag
{
	protected:
		array<float,25>a;
		int size;
	public:
		bag()
		{
			this->size=0;
		} 
        void populate( int n)
		{
		    a[0]=0;
         	for(int i=1;i<n;i++)
	        {
		      a[i]=1.0/i;
	        }
	        size=n;
		} 
        void insert(float sq, int n2) //insert sq at n2 index
        {
        	for(int i=size;i>=n2;i--) 
	        {
		       a[i]=a[i-1];
	        }
	        size++;
        	a[n2]=sq;
		}
        float extract(int index) 
        {
        	float removed=a[index];
        	for(int i=index;i<size-1;i++)
	        {
		      a[i]=a[i+1];
	        }
	        size--;
        	return removed;
		}
		
		void display()
		{
			cout<<a[0];
        	for(int i=1;i<size;i++)
        	{
        		cout<<" , "<<a[i];
			}
			cout<<endl;
			
		}
		
	friend	ostream & operator<<(ostream & os, const bag &b);
       
		
};

		ostream & operator<<(ostream & os, const bag &b)
        {
        	os<<b.a[0];
        	for(int i=1;i<b.size;i++)
        	{
        		os<<" , "<<b.a[i];
			}
			os<<endl;
			return os;
		}
int main()
{
	bag b;
	b.populate(5);
	cout<<b;
	//b.display();
	b.insert(1,0);
	b.display();
	b.extract(0);
	b.display();
	
}


/*
int main()
{
	array<float,25>a;
	int n ;
	cout<<"enter an integer less than equal to 20 : ";
	cin>>n;
	a[0]=0;
	for(int i=1;i<n;i++)
	{
		a[i]=1.0/i;
	}
	cout<<a[0];
	for(int j=1;j<n;j++)
	{
		cout<<","<<a[j];
	}
	//task 2
	cout<<endl;
	int n1 ;
	cout<<"enter an integer less than equal to 20(not the same as previous) : ";
	cin>>n1;
	if(n1!=n)
{
	//swap
	float x=a[n1];
	a[n1]=a[n-1];
	a[n-1]=x;
	
	cout<<endl;
	cout<<a[0];
	for(int j=1;j<n;j++)
	{
		cout<<","<<a[j];
    }
}
	//task 3
	int n2 ;
	cout<<endl<<"enter an integer less than equal to 20(not the same as previous) : ";
	cin>>n2;
	float sq=a[n2]*a[n2];
	for(int i=n;i>=n2;i--)
	{
		a[i]=a[i-1];
	}
	n++;
	
	a[n2]=sq;
	cout<<a[0];
	for(int j=1;j<n;j++)
	{
		cout<<","<<a[j];
    }
    
	//task 4
	int z=n/2;
	if(n%2==0)
	{
		z--;
	}
	
	cout<<endl;
	for(int i=z;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
	cout<<a[0];
	for(int j=1;j<n;j++)
	{
		cout<<","<<a[j];
    }
}
*/