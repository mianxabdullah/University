#include<stdio.h>
#include<windows.h>
#include<fstream>
#include<iostream>
using namespace std;

struct Student 
{ 
 int roll; 
 char name[30]; 
 Student():roll(0) 
 { 
  strcpy(name,"none"); 
 } 
}; 

// TASK3 BUFFERED:
class studarr
{
protected:
    Student* arr;
public:
    studarr(int n)
    {
        arr=new Student[n];
        for(int i=0;i<n;i++)
        {
            arr[i].roll=i;
        }
    }
};

void addToStudentBuffered(int N) 
{ 
  ofstream  ofs("studentdatabase.txt",ios::binary|ios::out); 
  studarr a(20000);
  ofs.write((char*)(&a),sizeof(studarr)*N); 
  ofs.close(); 
  cout<<endl<<"size:"<<sizeof(a)*N;

}

//task3 unbuffered
void addToStudentUnBuffered(int N) 
{ 
 ofstream  ofs("studentdatabase.txt",ios::binary|ios::out); 
 Student s;  
 for (int i=1; i<N; i++) 
 { 
  s.roll = i; 
  ofs.write((char*)(&s),sizeof(Student)); 
 } 
 ofs.close(); 
}
//task 4 unbuffered
void readAllRecordsUnBuffered(int N)
{
 ifstream  ifs("studentdatabase.txt",ios::binary|ios::in); 
 Student s;  
 for (int i=1; i<N; i++) 
 { 
  ifs.read((char*)(&s),sizeof(Student)); 
 } 
 ifs.close(); 
}  
//task4 buffered
void readAllRecordsBuffered(int N) 
{
  ifstream  ofs("studentdatabase.txt",ios::binary|ios::in); 
  studarr a(N);
  ofs.read((char*)(&a),sizeof(studarr)*N); 
  ofs.close();
}
int main()
{
    SYSTEMTIME systime;  
    cout<<"\nWriting Records to File one by one";  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;  
    addToStudentUnBuffered(20000);  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
    cout<<endl<<"buffered: ";
    addToStudentBuffered(20000);
}