#include "ratio.h"
using namespace std;
#include<iostream>
//1
    int rational::getNum() const
	{
		return this->num;
	}
  
    //2
	int rational::getDen() const
	{
		return this->den;
	}
  
    //3
	void rational::setNum(int p)
	{
		this->num = p;
	}

	//4
    void rational::setDen(int q)
	{
		this->den = q;
	}

	//5   
    void rational::display()
    {
      cout<<this->num<<"/";
      cout<<this->den;
    }

    //6
    int rational::setRational(int p, int q)
    {
       this->num=p;
       this->den=q;
    }

    //7
    rational rational::adinverse()
    {
       rational t;
       t.num=-this->den;
       t.den=this->num;
       return t;
    }

    //8
    rational rational::reciprocal()
    {
      rational t;
       t.num=this->den;
       t.den=this->num;
       return t;
    }

    //9
    rational rational::add(const rational &rhs) const
	{
		rational res;
		
		res.num = this->num*rhs.den + rhs.num*this->den;
		if(this->den!=rhs.den)
		{
		  res.den = this->den + rhs.den;
		}
		else
		res.den=this->den;
		//n1/d1 n2/d2=n1d2+n2d1/d1d2;
		return res;
	}

	//10
	 rational rational::multiply(const rational &rhs) const
	{
		rational res;
		
		res.num = this->num * rhs.num;
		res.den = this->den * rhs.den;
		
		return res;
	}

    //11

    rational rational::addint(int num)
    {
	  rational _r;
	  _r.num=this->num+(num*this->den);
	  _r.den=this->den;
      return _r;
    }

    //12
    rational rational::simplify()
    {
    		        // Calculate GCD using the Euclidean algorithm
        int a = this->num;
        int b = this->den;

        while (b != 0) 
		{
            int temp = b;
            b = a % b;
            a = temp;
        }

        // Simplify the rational number by dividing by the GCD
        this->num /= a;
        this->den /= a;
        rational s;
        s.num=this->num;
        s.den=this->den;
        return s;
    }

    //13
    bool rational::isequal(rational a)
    { 
      bool x=false;
      
      this->simplify();
      a.simplify();
      if(this->num==a.num && this->den==a.den)
      {
        x=true;
      }
       return x;
    }
    //14
    bool rational::isless(rational a)
    {
      bool l=false;
      float y= float(this->num)/float(this->den);
      float z= float(a.num)/float(a.den);
      if(y<z)
      {
        l=true;
      }
       return l;
    }
    //15
    bool rational::isgreater(rational a)
    {
      bool l=false;
      float y= float(this->num)/float(this->den);
      float z= float(a.num)/float(a.den);
      if(y>z)
      {
        l=true;
      }
       return l;
    }
    
