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

int maint0()
{
    Course pf;
    pf.setCode("CC-211");
    pf.setTitle("Programing Fundamentals");
    pf.setCreditHours(3);
    
    cout << "Details of PF are" << endl;
    cout << "Code   : " << pf.getCode() << endl;
    cout << "Title  : " << pf.getTitle() << endl;
    cout << "Credits: " << pf.getCreditHours() << endl;

	return 0;
}

int maint1()
{
    Course crs[3];

    crs[0].setCode("CC-211");
    crs[0].setTitle("Programing Fundamentals");
    crs[0].setCreditHours(3);

    crs[1].setCode("CC-311");
    crs[1].setTitle("Object Oriented Programing");
    crs[1].setCreditHours(4);

    crs[2].setCode("SS-201");
    crs[2].setTitle("Management");
    crs[2].setCreditHours(2);

    cout << "Details of Courses are" << endl;
    cout << "Code    Title         Credit" << endl;
    int j=0;
    while(j < 3)
    {
        cout << crs[j].getCode() << ", ";
        cout << crs[j].getTitle() << ", ";
        cout << crs[j].getCreditHours() << endl;
    j += 1;
    }
    
	return 0;
}

int maint2()
{
    Course *crs[3];

    crs[0] = new Course;
    crs[0]->setCode("CC-211");
    crs[0]->setTitle("Programing Fundamentals");
    crs[0]->setCreditHours(3);

    crs[1] = new Course;
    crs[1]->setCode("CC-311");
    crs[1]->setTitle("Object Oriented Programing");
    crs[1]->setCreditHours(4);

    crs[2] = new Course;
    crs[2]->setCode("SS-201");
    crs[2]->setTitle("Economics");
    crs[2]->setCreditHours(3);

    cout << "Using Pointers" << endl;
    cout << "Details of Courses are" << endl;
    cout << "Code    Title         Credit" << endl;
    int j=0;
    while(j < 3)
    {
        cout << crs[j]->getCode() << ", ";
        cout << crs[j]->getTitle() << ", ";
        cout << crs[j]->getCreditHours() << endl;
        j += 1;
    }
    
    delete crs[0];
    delete crs[1];
    delete crs[2];
    
	return 0;
}

int main()
{
    maint0();
    maint1();
    maint2();
    
	return 0;    
}