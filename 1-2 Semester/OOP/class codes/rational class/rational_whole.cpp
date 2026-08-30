#include<iostream>
#include<string>
using namespace std;
class rational
{  
   private:
    int num;
    int den;
   public:
    //function list
    
    int getNum() const;
    int getDen() const;
    void setNum(int p);
    void setDen(int q);
    void display();
    int setRational(int p, int q);
    rational adinverse();
    rational reciprocal();
    rational add(const rational &rhs) const;
    rational multiply(const rational &rhs) const;
    rational addint(int num);
    rational simplify();
    bool isequal(rational a);
    bool isless(rational a);
	bool isgreater(rational a); 
  
    
    //constructors
    rational(int p, int q) // natural constructor
	{
		this->num = p;
		this->den = q;		
	}

	rational() // default constructor 
	{
		this->num = 0;
		this->den = 0;		
	}

    // explicit
	rational(int n) // type cast constructor
	{
		this->num = n;
		this->den = 1;		
	}
	
	rational(const rational &r) // copy constructor customization
	{
		this->num = r.num;
		this->den = r.den;		
	}

	/*~rational() // destructor
	{
		cout << "\n[dying . . . (";
		this->display();
		cout << ") . . . . died!]\n";
	}*/

};


int main()
{   
    rational r(1,2);
    cout<<"rational number by constructor : ";
    r.display();
    cout<<endl; 
        
    rational r1;
    r1.setNum(5);
    r1.setDen(7);
    cout<<"rational number by setting num and den seperately : ";
    r1.display();
    
    cout<<endl;
    int a=r1.getNum();
    int b=r1.getDen();
    cout<<a<<"/"<<b;
    
    cout<<endl;
    rational r2;
    r2.setRational(3,4);
    cout<<"rational number by setRational :";
    r2.display();
    
    cout<<endl;
    rational r3(7,8);
    cout<<"additive inverse of ";
	r3.display();
	cout<<" is : ";
    r3.adinverse().display();
    cout<<endl;
    
    rational r4(8,9);
    cout<<"reciprocal of ";
    r4.display();
    cout<<" is : ";
    r4.reciprocal().display();
    cout<<endl;
    
    rational r5(3,4);
    rational r6(7,4);
    cout<<"Addition of ";
    r5.display();
    cout<<" and ";
    r6.display();
    cout<<" is : ";
    r5.add(r6).display();
    cout<<endl;
    
    
    cout<<"multiplication of ";
    r5.display();
    cout<<" and ";
    r6.display();
    cout<<" is : ";
    r5.multiply(r6).display();
    cout<<endl;
    
    rational r7(20,2);
    cout<<"addition of an integer 5 with ";
    r7.display();
    cout<<" is : ";
    r7.addint(5).display();
	
	cout<<endl;
	rational r8(20,4);
	cout<<"simplified form of ";
	r8.display();
	cout<<" is : ";
	r8.simplify().display();
	cout<<endl;
	
	rational r9(2,4);
	rational r10(1,2);
	if (r9.isequal(r10)) 
	{
        cout << "The fractions are equal!" << endl;
    } 
	else 
	{
        cout << "The fractions are not equal!" << endl;
    }
	//cout<<"isEqual : "<<r9.isequal(r10);
	//r9.isequal(r10);
	
	
	cout<<endl;
	
	rational r11(8,7);
	rational r12(7,8);
	if (r11.isless(r12)) 
	{
        cout << "the fraction on left is less" << endl;
    } 
	else 
	{
        cout << "the fraction on right is less" << endl;
    }
	
    cout<<endl;
	
	rational r13(8,7);
	rational r14(7,8);
	if (r13.isgreater(r14)) 
	{
        cout << "the fraction on left is greater" << endl;
    } 
	else 
	{
        cout << "the fraction on left is not greater" << endl;
    }
}


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
    
