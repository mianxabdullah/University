#include<iostream>
using namespace std;
class queue
{
	protected:
		int data[100];
		int q_size;
		
		void advance();
		
	public:
		void add(int n);
		int remove();
		double front() const;
		int size() const;
		bool isEmpty() const;
		bool isFull() const;
		queue();
};
int main()
{
	queue q1;
	q1.add(55);
	q1.add(65);
	q1.add(75);
	q1.add(85);
	cout<<q1.isEmpty()<<endl;
	cout<<q1.isFull()<<endl;
	cout<<"the entity "<<q1.remove()<<" has been removed"<<endl;
	cout<<"Size of queue is : "<<q1.size()<<endl;
	cout<<"the entity "<<q1.remove()<<" has been removed"<<endl;
	cout<<"Size of queue is : "<<q1.size()<<endl;
}

void queue::add(int n)
{
    if (q_size < 50) 
	{
        data[q_size] = n;
        q_size++;
    }
}
void queue::advance()
{
    for (int i = 0; i < q_size - 1; i++) 
		{
            data[i] = data[i + 1];
        }
}



int queue::remove()
{
    if (q_size > 0) 
	{
        int removedValue = data[0];
        this->advance();
        q_size--;
        return removedValue;
    } 
	else 
	{
         throw string("Empty");
    }
}
double queue::front() const
{
	if(q_size>0)
	{
		return this->data[0];
	}
	else
    {
        throw string("Empty");
    }
}


bool queue::isEmpty() const
{
	bool r=false;
	if(q_size==0)
	{
		r=true;
	}
	return r;
}
bool queue::isFull() const
{
	bool r=false;
	if(q_size==100)
	{
		r=true;
	}
	return r;
}
int queue::size() const
{
	int r=q_size;	
	return r;
}
queue::queue ()
{
	q_size=0;
}
