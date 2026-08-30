#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class item
{
	protected:
		int sno;
		double quantity;
		string attribute;
		double rate;
	public:
		int getsno() const
		{
			return this->sno;
		}
		void setsno(double sn)
		{
			this->sno=sn;
		}
		
		
		
		double getQuantity() const
		{
			return this->quantity;
		}
		void setQuantity(double qty)
		{
			this->quantity=qty;
		}
		
		
		string getAttribute() const
		{
			return this->attribute;
		}
		void setAttribute(string attr)
		{
			this->attribute=attr;
		}
		
		
		double getRate() const
		{
			return this->rate;
		}
		void setRate(double rat)
		{
			this->rate=rat;
		}
		
		void setItem(double qty,string attr,double rat)
		{
			this->quantity=qty;
			this->attribute=attr;
			this->rate=rat;
		}
		
		double getAmount() const
		{
			return (this->quantity*this->rate);
		}
		
		void print_item() const
		{
			cout<<"Quantity: "<<this->quantity<<" Description: "<<this->attribute<<" rate: "<<this->rate<<" Amount: "<<this->getAmount();
		}
		
};

class date
{
	protected:
		int day;
		int month;
		int year;
	public:
		date(int d, int m, int y)
		{
			if (day<=31&&day>=1&&month<=12&&month>=1&&year>0)
			{
				this->day=d;
				this->month=m;
				this->year=y;
				
			}
		}
		
		date(const date &x)
		{
			if (x.day<=31&&x.day>=1&&x.month<=12&&x.month>=1&&x.year>0)
			{
				this->day=x.day;
				this->month=x.month;
				this->year=x.year;
				
			}
		}
		
		
		
		int getDay() const
		{
			return this->day;
		}
		void setDay(int day)
		{
			if (day<=31&&day>=1)
			{
				this->day=day;
		    }
		    else 
			{
			    throw 99;
			}
		    		
		}
		
		int getMonth() const
		{
			return this->month;
		}
		void setMonth(int month)
		{
			if (month<=12&&month>=1)
			{
				this->month=month;
		    }
		    else 
		    {
		    	throw 99;
		    }
		}
		
		int getYear() const
		{
			return this->year;
		}
		void setYear(int year)
		{
			if (year>0)
			{
				
				this->year=year;
		    }
		    else 
		    {
		    	throw 99;
		    }
		}
		
		void setDate(int day, int month,int year)
		{
			if (day<=31&&day>=1&&month<=12&&month>=1&&year>0)
			{
				this->day=day;
				this->month=month;
				this->year=year;
				
			}
		}
		
		void print_date() const
		{
			cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
		}
		
};

class name
{
	protected:
		string attribute;
		string f_name;
		string l_name;
	public:
		string getAttribute() const
		{
			return this->attribute;
		}
		void setAttribute(string attr)
		{
			this->attribute=attr;
		}
		
		
		string getFname() const
		{
			return this->f_name;
		}
		void setFname(string fname)
		{
			this->f_name=fname;
		}
		
		
		string getLname() const
		{
			return this->l_name;
		}
		void setLname(string lname)
		{
			this->l_name=lname;
		}
		
		void setName (string attr,string fname,string lname)
		{
			this->attribute=attr;
			this->f_name=fname;
			this->l_name=lname;
		}
		
		void print_name() const
		{
			cout<<this->attribute<<" "<<this->f_name<<" "<<this->l_name<<endl;
		}
};

class address
{
	protected:
		int Hno;
		int STno;
		string town;
		string city;
	public:
		void setHno(int hno)
		{
			this->Hno=hno;
		}
		int getHno() const
		{
			return this->Hno;
		}
		
		
		void setSTno(int stno)
		{
			this->STno=stno;
		}
		int getSTno() const
		{
			return this->STno;
		}
		
		void setTown(string town)
		{
			this->town=town;
		}
		string getTown() const
		{
			return this->town;
		}
		
		
		void setCity(string city)
		{
			this->city=city;
		}
		string getCity() const
		{
			return this->city;
		}
		
		void setAddr(int hno,int stno,string town,string city)
		{
			this->Hno=hno;
			this->STno=stno;
			this->town=town;
			this->city=city;
		}
		
		void print_address() const
		{
			cout<<"House NO: "<<this->Hno<<" Street NO: "<<this->STno<<" ,"<<this->town<<" ,"<<this->city<<endl;
		}
		
		
};

class cash_memo
{
	protected:
		date *dt;
	    name customer_name;
		address customer_addr;
		item itm[10];  //sno,quantity,attribute,rate 
		int item_count;
		double total;
		static string business_name;
		static string business_slogan;
		static string owner_cell;
	public:
	cash_memo()
	{
		this->total=0;
		this->item_count=0;
	}
	
	void setDate(date *d) 
	{
         dt=d;
        
    }
		

    void setCustomerName(string attr, string fname, string lname) 
	{
        customer_name.setAttribute(attr);
        customer_name.setFname(fname);
        customer_name.setLname(lname);
    }

    void setCustomerAddress(int hno, int stno, string town, string city) 
	{
        customer_addr.setHno(hno);
        customer_addr.setSTno(stno);
        customer_addr.setTown(town);
        customer_addr.setCity(city);
    }
	
	
    void addItem(int sn,string attr, double qty, double rate) 
	{
        if (item_count < 10) 
		{
			itm[item_count].setsno(sn);
            itm[item_count].setAttribute(attr);
            itm[item_count].setQuantity(qty);
            itm[item_count].setRate(rate);
            total += itm[item_count].getAmount();
            item_count++;
        } 
		else 
		{
            cout << "limit exceed" << endl;
        }
    }	
	
    void print() const 
	{
        cout << "           " << business_name << endl;
        cout << "          " << business_slogan << endl;
        cout << "      Owner Cell: " << owner_cell << endl;
        cout << "------------------------------------------------------------" << endl;
        //cout << "Serial Number: " << sno << endl;
        cout << "Date: ";
        dt->print_date();
        cout << "Customer Name: ";
        customer_name.print_name();
        cout << "Customer Address: ";
        customer_addr.print_address();
        cout << "-------------------------------------------------------------" << endl;
        cout<<"SNo.   "<< left << setw(20) << "Items" << setw(15) << "Quantity" << setw(15) << "Rate" << setw(15) << "Amount" << endl;


        for (int i = 0; i < item_count; i++) 
		{
         cout<<itm[i].getsno()<<"      " 
		 << left << setw(20) << itm[i].getAttribute() 
         << setw(15) << itm[i].getQuantity() 
         << setw(15) << itm[i].getRate() 
         << setw(15) << itm[i].getAmount() << endl;
        }

        cout << "--------------------------------------------------------------" << endl;
        cout  << setw(20) << "Total Amount: " << total << endl;
    }
		

		
};

string cash_memo::business_name = "MOBILE KING";
string cash_memo::business_slogan = "Quality First";
string cash_memo::owner_cell = "0332-1111111";

int main()
{
	date dte(3,9,2006); //aggregation
    cash_memo c;
    c.setDate(&dte); //passed as reference
    c.setCustomerName("Mr.", "Ali", "Akram");
    c.setCustomerAddress(4, 5, "Downtown", "Lahore");
    c.addItem(1,"Mobile Phone", 2, 50000.0);
    c.addItem(2,"Headphones", 1, 300.0);
    c.addItem(3,"Charger", 3, 500.0);
    c.print();
}