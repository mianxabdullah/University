#include<iostream>
#include<string>

using namespace std;

class Course
{
    private:
        string code;
        string title;
        float creditHours;
    public:
        string getCode()
        {
            return code;
        }
        
        void setCode(string _code)
        {
            code = _code;
        }
        
        string getTitle()
        {
            return title;
        }
        
        void setTitle(string _title)
        {
            title = _title;
        }
        
        float getCreditHours()
        {
            return creditHours;
        }
        
        void setCreditHours(float _crHrs)
        {
            creditHours = _crHrs;
        }
        
};

int main()
{
    Course pf[4];
    
    pf[0].setCode("CC-211");
    pf[0].setTitle("Programing Fundamentals");
    pf[0].setCreditHours(3);
    
    pf[1].setCode("iCt-211");
    pf[1].setTitle("ict");
    pf[1].setCreditHours(3);
    
    pf[2].setCode("qt-211");
    pf[2].setTitle("quran translation");
    pf[2].setCreditHours(1);
    
    pf[3].setCode("id-211");
    pf[3].setTitle("ideology");
    pf[3].setCreditHours(2);
    
    
    for(int i=0;i<4;i++)
	{
	cout << "Details of course "<< i+1  << " :"<< endl;
    cout << "Code   : " << pf[i].getCode() << endl;
    cout << "Title  : " << pf[i].getTitle() << endl;
    cout << "Credits: " << pf[i].getCreditHours() << endl;
    }
	return 0;
}