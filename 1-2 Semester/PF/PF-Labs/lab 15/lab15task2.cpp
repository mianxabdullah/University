#include <iostream>
#include <string>
using namespace std;
struct Department 
{
    string name;
    int id;
};
struct Teacher 
{
    string name;
    int age;
    Department* dept;
};

int main() 
{
    Teacher teacher1;
    teacher1.name = "dr idrees";
    teacher1.age = 48;
    teacher1.dept= new Department;
    teacher1.dept->name = "data science";
    teacher1.dept->id = 001;

    Teacher teacher2;
    teacher2.name = "dr abdullah";
    teacher2.age = 37;
    teacher2.dept= new Department;
    teacher2.dept->name = "data science";
    teacher2.dept->id =002 ;
    
    Teacher teacher3;
    teacher3.name = teacher1.name;
    teacher3.age = teacher1.age;
    teacher3.dept= new Department;
    teacher3.dept->name = teacher1.dept->name;
    teacher3.dept->id =teacher1.dept->id ;
    
    

    cout << "Teacher 1:" << endl;
    cout << "Name: " << teacher1.name << endl;
    cout << "Age: " << teacher1.age << endl;
    cout << "Department: " << teacher1.dept->name << " (" << teacher1.dept->id << ")" << endl;

    cout << "\nTeacher 2:" << endl;
    cout << "Name: " << teacher2.name << endl;
    cout << "Age: " << teacher2.age << endl;
    cout << "Department: " << teacher2.dept->name << " (" << teacher2.dept->id << ")" << endl;
    
    cout<<endl<<"DEEP COPY:"<<endl;
    cout << "Teacher 3:" << endl;
    cout << "Name: " << teacher3.name << endl;
    cout << "Age: " << teacher3.age << endl;
    cout << "Department: " << teacher3.dept->name << " (" << teacher3.dept->id << ")" << endl;
    
    delete teacher1.dept ;
    
    
    delete teacher2.dept ;
   
    
    delete teacher3.dept ;
   
   
}


