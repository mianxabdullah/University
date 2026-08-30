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

class student
{
    private:
        string name;
        string rollNo;
        float creditHours;
        Course courses[3];
        
    public:
        string getname()
        {
            return name;
        }
        
        void setname(string _name)
        {
            name = _name;
        }
        
        string getrollNo()
        {
            return rollNo;
        }
        
        void setrollNo(string _rollNo)
        {
            rollNo = _rollNo;
        }
        
        float getCreditHour()
        {
            return creditHours;
        }
        
        void setCreditHours(float _crHrs)
        {
            creditHours = _crHrs;
        }
        //
        
        void setCourseTitle(string name , int index )
        {
           courses[index].setTitle(name);	
		}
		void setCourseCode(string code , int index )
        {
           courses[index].setCode(code);	
		}
		void setCourseCreditHour(float ch , int index )
        {
           courses[index].setCreditHours(ch);	
		}
		
		//
		 string getCourseTitle( int index )
        {
           string names=courses[index].getTitle();	
           return names;
		}
		string getCourseCode( int index )
        {
           string cc=courses[index].getCode();
		   return cc;	
		}
		float getCourseCreditHour( int index )
        {
           float cr=courses[index].getCreditHours();
		   return cr;	
		}
		
		
        
        
};

int maint1()
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
int maint2()
{
	 Course *pf= new Course[4];
    
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
	delete [] pf;
}
int main()
{
	string name,rollno,code,title;
	float cr,ch;
	student st;
	cout<<"enter student name";
	cin>>name;
	st.setname(name);
	cout<<"enter student roll no";
	cin>>rollno;
	st.setrollNo(rollno);
	cout<<"enter student credit hours";
	cin>>cr;
	st.setCreditHours(cr);
	
	for(int i=0;i<3;i++)
	{
	
	cout<<"enter"<<i+1<<" course title , code, credit hours :";
	cin>>title>>code>>ch;
	st.setCourseCreditHour(ch,i);
	st.setCourseCode(code,i);
	st.setCourseTitle(title,i);
    
	
    }
    cout<<"student Name : " <<st.getname() <<endl;
	cout<<"student Rollno : " <<st.getrollNo() <<endl;
	cout<<"student CreditHours : " <<st.getCreditHour() <<endl;
	for(int j=0;j<3;j++)
	{
		
		cout<<"course "<< j+1<<"title : "<< st.getCourseTitle(j)<<endl;
		cout<<"course "<< j+1<<" code : "<< st.getCourseCode(j)<<endl;
		cout<<"course "<< j+1<<"credit hours : "<< st.getCourseCreditHour(j)<<endl;
	}
}

