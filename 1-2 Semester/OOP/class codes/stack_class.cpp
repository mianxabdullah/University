#include<iostream>
using namespace std;
class stack
{
	protected:
		int data[100];
		int n;
		
	public:
		void add(int n);
		int remove();
		double front() const;
		int size() const;
		bool isEmpty() const;
		bool isFull() const;
		stack();
};
int main()
{
	stack s1;
	s1.add(55);
	s1.add(65);
	s1.add(75);
	s1.add(85);
	cout<<s1.isEmpty()<<endl;
	cout<<s1.isFull()<<endl;
	cout<<"the entity "<<s1.remove()<<" has been removed"<<endl;
	cout<<"Size of stack is : "<<s1.size()<<endl;
	cout<<"the entity "<<s1.remove()<<" has been removed"<<endl;
	cout<<"Size of queue is : "<<s1.size()<<endl;
}

void stack::add(int a)
{
    if (n<100) 
	{
        data[n] = a;
        n++;
    }
}

int stack::remove()
{
    if (n > 0) 
	{
        int removedValue = data[n-1];
        
        n--;
        return removedValue;
    } 
	else 
	{
         throw string("Empty");
    }
}
double stack::front() const
{
	if(n>0)
	{
		return this->data[0];
	}
	else
    {
        throw string("Empty");
    }
}


bool stack::isEmpty() const
{
	bool r=false;
	if(n==0)
	{
		r=true;
	}
	return r;
}
bool stack::isFull() const
{
	bool r=false;
	if(n==100)
	{
		r=true;
	}
	return r;
}
int stack::size() const
{	
	return this->n;
}
stack::stack ()
{
	n=0;
}