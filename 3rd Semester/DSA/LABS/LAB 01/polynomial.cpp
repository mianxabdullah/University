#include"poly.h"
    polynomial::polynomial(int s=1)
    {
        coeff = new int [s];
        for(int i=0;i<s;i++)
        {
            coeff[i]=0;
        }
        capacity=s;
        size=0;
    }
    polynomial::polynomial(const polynomial &rhs)
    {
        coeff=new int [rhs.capacity];
        capacity=rhs.capacity;
        size=rhs.size;
        for (int i=0;i<capacity;i++)
        {
            coeff[i]=(i < rhs.size) ? rhs.coeff[i] : 0;
        }
    }
    polynomial& polynomial::operator=(polynomial& rhs)
    {
        if (this != &rhs) 
        {
            delete[] coeff;                      
            capacity = rhs.capacity;
            size = rhs.size;
            coeff = new int[capacity];           
            for (int i = 0; i < capacity; i++) 
            {
                coeff[i] = (i < rhs.size) ? rhs.coeff[i] : 0;         
            }
        }
       return *this;
    }
    polynomial::~polynomial()
    {
        delete[] coeff;
    }
    void polynomial::resize(int pow)
	{
        int newCapacity= pow +2;
        int* newcoeff= new int[newCapacity];
        
		for(int i=0;i<newCapacity;i++)
		{
			newcoeff[i]=(i < size) ? coeff[i] : 0;
		}
		delete[] coeff;
		coeff=newcoeff;
		capacity=newCapacity;
	}
    void polynomial::addTerm(int co,int pw)
    {
        if(capacity <= pw)
        {
            resize(pw);
        }
        coeff[pw] += co;
        if (pw + 1 > size) 
        {
            size = pw + 1;
        }

    }
    int polynomial::degree()
    {
        return size-1;
    }
    int polynomial::getCoefficient(int power)
    {
        return (power<size)?coeff[power]:0;
    }
    void polynomial::setCoefficient(int c,int p )
    {
        if (p >= capacity) 
        {
            resize(p);
        }
        coeff[p]=c;
        if (p + 1 > size) 
        {
            size = p + 1;
        }
    }
    int polynomial::operator() (int value)
    {
        int ans=0;
        for(int i=0; i<size+1; i++)
        {
            ans += coeff[i]*pow(value,i);
        }
        return ans;
        
    }
    polynomial &polynomial::operator+=(const polynomial &rhs)
    {
        if (rhs.size > capacity) 
        {
            resize(rhs.size - 1);
        }

        for (int i = 0; i < rhs.size; i++) 
        {
            coeff[i] += rhs.coeff[i];
        }

        if (rhs.size > size) 
        {
            size = rhs.size;
        }

        return *this;
    }
    polynomial polynomial::operator+(const polynomial& rhs) const
    {

        int maxi = max(size, rhs.size);
        polynomial result(*this);
        if (result.capacity < maxi) 
        {
            result.resize(maxi - 1);
        }
        result+=rhs;
        return result;
    }
    polynomial &polynomial::operator-=(const polynomial &rhs) 
    {
        if (rhs.size > capacity) 
        {
            resize(rhs.size - 1);
        }

        for (int i = 0; i < rhs.size; i++) 
        {
            coeff[i] -= rhs.coeff[i];
        }

        if (rhs.size > size) 
        {
            size = rhs.size;
        }

        return *this;
    }
    polynomial polynomial::operator-(const polynomial& rhs) const
    {
        int maxi = max(size, rhs.size);
        polynomial result(*this);
        if (result.capacity < maxi) 
        {
            result.resize(maxi - 1);
        }
        result-=rhs;
        return result;
    }
    polynomial polynomial::operator*(polynomial &rhs)
    {
        polynomial result(size + rhs.size); // degree = sum of degrees
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < rhs.size; j++) 
            {
                result.coeff[i+j] += coeff[i] * rhs.coeff[j];
            }
        }
        result.size = size + rhs.size - 1;
        return result;
    }
    void polynomial::clear()
    {
        for (int i=0;i<size;i++)
        {
            coeff[i]=0;
        }
        size=0;

    }
    ostream& operator<<(ostream &out, const polynomial &p)
    {
        for(int i=0;i<p.size;i++)
        {
            if (p.coeff[i] != 0)
            {
                out<< p.coeff[i]<<"x^"<<i;
                if (i != p.size - 1) 
                {    
                    out << " + ";
                }
            } 
        }
        return out;
    }
    void polynomial::derivative()
    {
        for (int i=0;i<size;i++)
        {
            coeff[i]=i*coeff[i];
        }
        for (int i=0;i<size;i++)
        {
            coeff[i]=coeff[i+1];
        }
        cout<<*this;
    }
    void polynomial::Antiderivative()
    {
        if (capacity <= size) 
        {
            resize(size+1); 
        }
        for (int i=size;i>=0;i--)
        {
            coeff[i+1] = coeff[i] / (i+1);
        }
        coeff[0] = 0;  
        size += 1;
        cout<<*this;
    } 
    void polynomial::addtoCoefficient(int c,int p )
    {
        if (p >= capacity) 
        {
            resize(p);
        }
        coeff[p]=coeff[p]+c;
        if (p + 1 > size) 
        {
            size = p + 1;
        }
    }
