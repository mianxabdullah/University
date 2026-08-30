#include<iostream>
#include<string>

using namespace std;


class robot
{
	private:
      string name;
      int row, col;
      char direction; // u(up), d(down), l(left), r(right) on Cartesian plane
      int arr[100][100]={0};
    public:
       string getRobotName() const ;
       void setRobotName(string n) ;
       int getLocationX() const ;
       void setLocationX(int v) ;
       int getLocationY() const ;
       void setLocationY(int v) ;
       char getDirection() const ;
       void setDirection (char d) ;
       void setRobot(string n, int cx, int cy, char d); 
       bool canStep();
       void takeStep();
       void turnLeft ();
       void turnRight ();
       void turnBackword ();
       void display() const ;
       int distanceX(const robot &x) const;
	   int distanceY(const robot &y) const;
};
string robot::getRobotName() const
{
	return this->name;	
}
void robot::setRobotName(string n) 
{
  this->name=n;	
}
int robot::getLocationX() const 
{
	return this->row;
}
void robot::setLocationX(int v) 
{
	this->row=v;
}
int robot::getLocationY() const 
{
	return this->col;
}
void robot::setLocationY(int v) 
{
	this->col=v;
}
char robot::getDirection() const 
{
	return this->direction;
}
void robot::setDirection (char d) 
{
	this->direction=d;
}
void robot::setRobot(string n, int cx, int cy, char d) 
{
	this->name=n;
	this->row=cx;
	this->col=cy;
	this->direction=d;
}
bool robot::canStep()
{
	if(this->direction=='u'&& row>0 ) 
	{
		return true;
	}
	else if(this->direction=='d'&& row<99 ) 
	{
		return true;
	}
	else if(this->direction=='l'&& col>0 ) 
	{
		return true;
	}
	else if(this->direction=='r'&& col<99 ) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
void robot::takeStep()
{
	if(canStep())
	{
	if(this->direction=='u' ) 
	{   
		row--;
	}
	else if(this->direction=='d' ) 
    {   
		row++;
	}
	else if(this->direction=='l' ) 
    {   
		col--;
	}
	else if(this->direction=='r' ) 
    {   
		col++;
	}
	   
	}
	else
	{
		cout<<"cannot take step";
	}
}
void robot::turnLeft ()
{
	
	if(this->direction=='u' ) 
	{   
		this->direction='l';
	}
	else if(this->direction=='d' ) 
    {   
		this->direction='r';
	}
	else if(this->direction=='l' ) 
    {   
		this->direction='d';
	}
	else if(this->direction=='r' ) 
    {   
		this->direction='u';
	}
}
void robot::turnRight ()
{
	if(this->direction=='u' ) 
	{   
		this->direction='r';
	}
	else if(this->direction=='d' ) 
    {   
		this->direction='l';
	}
	else if(this->direction=='l' ) 
    {   
		this->direction='u';
	}
	else if(this->direction=='r' ) 
    {   
		this->direction='d';
	}
}
void robot::turnBackword ()
{
	if(this->direction=='u' ) 
	{   
		this->direction='d';
	}
	else if(this->direction=='d' ) 
    {   
		this->direction='u';
	}
	else if(this->direction=='l' ) 
    {   
		this->direction='r';
	}
	else if(this->direction=='r' ) 
    {   
		this->direction='l';
	}
	
}
void robot::display() const 
{
	cout<<name<<" is at ("<<row<<","<<col<<") towards "<<direction;
}
int robot::distanceX(const robot &x) const
{
    int difx=abs(x.row-row);
    return difx;
}
int robot::distanceY(const robot &y) const
{
    int dify=abs(y.col-col);
    return dify;
}





int main()
{
	robot r1;
	r1.setRobot("jon",3,4,'d');
	r1.display();
	r1.turnLeft();
	cout<<endl;
	r1.display();
	r1.takeStep();
	cout<<endl;
	r1.display();
	cout<<endl;
	cout<<endl;
	robot r[6];
	r[0].setRobot("R",1,1,'r');
	r[1].setRobot("S",10,10,'l');
	r[2].setRobot("T",20,20,'d');
	r[3].setRobot("Q",30,30,'u');
	r[4].setRobot("P",40,40,'d');
	r[5].setRobot("Z",50,50,'r');
	for(int i=0;i<6;i++)
	{
	  r[i].display();	
	  cout<<endl;
	}
	cout<<endl;
	cout<<"After Moving:"<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<4;j++)
		{
			r[i].takeStep();
		}
	}
	
	for(int i=0;i<6;i++)
	{
	  r[i].display();	
	  cout<<endl;
	}
	
	cout<<endl;
	cout<<endl;
	
	cout<<" MOVING TOWARDS T: "<<endl;
	
	
	bool reached[5] = {false}; // Track robots reaching near T
    int remaining = 5; // Robots still moving

    while (remaining > 0) 
	{
        for (int i = 0; i < 5; i++) 
		{  // Ignore T (robots[2])
            if (reached[i]) continue; // Skip if already reached

            int dx=r[0].distanceX(r[2]);
        	int dy=r[0].distanceY(r[2]);

            // Stop if adjacent
            if (dx <= 1 && dy <= 1) 
			{
                cout << r[i].getRobotName() << " reached near T!\n";
                reached[i] = true;
                remaining--;
            } 
			else 
			{
                // Move X direction first
                if (r[i].getLocationX() < r[2].getLocationX()) 
				{
                    r[i].setDirection('d'); // Move Down
                } 
				else if (r[i].getLocationX() > r[2].getLocationX()) 
				{
                    r[i].setDirection('u'); // Move Up
                } 
                // Move Y direction next
                else if (r[i].getLocationY() < r[2].getLocationY()) 
				{
                    r[i].setDirection('r'); // Move Right
                } 
				else 
				{
                    r[i].setDirection('l'); // Move Left
                }

                r[i].takeStep(); // Move one step
            }
        }
    }

    cout << "\nFinal Positions:\n";
    for (int i = 0; i < 6; i++) 
	{
        r[i].display();
        cout << endl;
    }

	
	
	
	
}



/*
	cout<<" Moving Towards T :"<<endl;
	int X=r[2].getLocationX();
	int Y=r[2].getLocationY();
	
	r[0].setLocationX(X+1);
	r[1].setLocationX(X-1);
	r[3].setLocationX(X);
	r[4].setLocationX(X);
	r[5].setLocationX(X);

	
	r[0].setLocationY(Y);
	r[1].setLocationY(Y);
	r[3].setLocationY(Y+1);
	r[4].setLocationY(Y-1);
	r[5].setLocationY(Y-3);
		
	r[0].display();
	cout<<endl;
	r[1].display();
	cout<<endl;
	r[3].display();
	cout<<endl;
	r[4].display();
	cout<<endl;
	r[5].display();
	
	cout<<endl;*/