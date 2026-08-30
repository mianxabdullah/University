#ifndef ratio_h
#define ratio_h
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
#endif