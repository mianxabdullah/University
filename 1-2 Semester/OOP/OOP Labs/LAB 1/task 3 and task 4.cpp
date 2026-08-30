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

class Student
{
    private:
        string rollno;
        string name;
        int semester;
        Course courses[3];
    public:
        string getRollNo()
        {
            return rollno;
        }
        
        void setRollNo(string _rollno)
        {
            rollno = _rollno;
        }
        
        string getName()
        {
            return name;
        }
        
        void setName(string _name)
        {
            name = _name;
        }
        
        int getSemester()
        {
            return semester;
        }
        
        void setSemester(int _semester)
        {
            semester = _semester;
        }
        
        Course getCourse(int courseIndex)
        {
            return courses[courseIndex];
        }
        
        void setCourse(int courseIndex, Course _course)
        {
            courses[courseIndex] = _course;
        }
};

int maint3()
{
    Student s1;

    string rno;
    string nme;
    int sem;
    string cod;
    string ttl;
    float chrs;
    
    cout << "Enter student roll no: ";
    getline(cin, rno);
    cout << "Enter student name: ";
    getline(cin, nme);
    cout << "Enter student semester: ";
    cin >> sem;
    
    s1.setRollNo(rno);
    s1.setName(nme);
    s1.setSemester(sem);
    for (int j=0; j<3; j+=1)
    {
        Course c;
        cout << "Enter Course code: ";
        if (cin.peek() == '\n') cin.ignore(1);
        getline(cin, cod);
        cout << "Enter Course title: ";
        getline(cin, ttl);
        cout << "Enter Course Credits: ";
        cin >> chrs;
        
        c.setCode(cod);
        c.setTitle(ttl);
        c.setCreditHours(chrs);
        s1.setCourse(j, c);
    }
    
    cout << endl << endl;
    cout << "Details of the student are" << endl;
    cout << "Roll No  : " << s1.getRollNo() << endl;
    cout << "Name     : " << s1.getName() << endl;
    cout << "Semester : " << s1.getSemester() << endl;
    cout << "Courses taken are" << endl;
    cout << "Code    Title        Credits" << endl;
    for (int j=0; j<3; j+=1)
    {
        cout << s1.getCourse(j).getCode() << " ";
        cout << s1.getCourse(j).getTitle() << " ";
        cout << s1.getCourse(j).getCreditHours() << endl;
    }
    
	return 0;
}

int maint4()
{
    Student s1;
    float marks[3];
    
    string rno;
    string nme;
    int sem;
    string cod;
    string ttl;
    float chrs;
    
    cout << "Enter student roll no: ";
    getline(cin, rno);
    cout << "Enter student name: ";
    getline(cin, nme);
    cout << "Enter student semester: ";
    cin >> sem;
    
    s1.setRollNo(rno);
    s1.setName(nme);
    s1.setSemester(sem);
    for (int j=0; j<3; j+=1)
    {
        Course c;
        float mrk;
        cout << "Enter Course code: ";
        if (cin.peek() == '\n') cin.ignore(1);
        getline(cin, cod);
        cout << "Enter Course title: ";
        getline(cin, ttl);
        cout << "Enter Course Credits: ";
        cin >> chrs;
        cout << "Enter Course Marks: ";
        cin >> mrk;
        
        c.setCode(cod);
        c.setTitle(ttl);
        c.setCreditHours(chrs);
        s1.setCourse(j, c);
        marks[j] = mrk;
    }
    
    
    float totalCredits = 0.0f, totalMarks = 0.0f;
    cout << endl << endl;
    cout << "Details of the student are" << endl;
    cout << "Roll No  : " << s1.getRollNo() << endl;
    cout << "Name     : " << s1.getName() << endl;
    cout << "Semester : " << s1.getSemester() << endl;
    cout << "Courses taken are" << endl;
    cout << "Code    Title        Credits     Marks" << endl;
    for (int j=0; j<3; j+=1)
    {
        cout << s1.getCourse(j).getCode() << " ";
        cout << s1.getCourse(j).getTitle() << " ";
        cout << s1.getCourse(j).getCreditHours() << " ";
        cout << marks[j] << endl;
        totalCredits += s1.getCourse(j).getCreditHours();
        totalMarks += marks[j];
    }
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Marks  : " << totalMarks << endl;
    
	return 0;
}

int main()
{
	//maint3();
    //maint4();
    
    return 0;
}
 