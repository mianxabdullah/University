#include <iostream>
#include <string>
using namespace std;
struct Date 
{
    int day;
    int month;
    int year;
};
string alphaDate(const Date& date) //previously made function
{
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (date.month < 1 || date.month > 12) 
	{
        throw "Month value can be within 1 to 12";
    }

    int maxDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //last dates
    
	if (date.day < 1 || date.day > maxDays[date.month - 1]) 
	{
        throw "Days are invalid for the month of " + months[date.month - 1];
    }

    return months[date.month - 1] + " " + to_string(date.day) + ", " + to_string(date.year);
}

void mainFunction1() //main without try and catch
{
    Date date = {10, 6, 1997};
    cout << alphaDate(date) << endl;

    date = {3, 3, 2016};
    cout << alphaDate(date) << endl;

    date = {31, 8, 2009};
    cout << alphaDate(date) << endl;

    date = {31, 13, 2009};
    cout << alphaDate(date) << endl;

}
void mainFunction2() //main with try and catch
{
    try 
	{
        Date date1 = {10, 6, 1997};
        cout << alphaDate(date1) << endl;

        Date date2 = {3, 3, 2016};
        cout << alphaDate(date2) << endl;

        Date date3 = {31, 8, 2009};
        cout << alphaDate(date3) << endl;

        Date date4 = {31, 13, 2009};
        cout << alphaDate(date4) << endl;
    } 
	catch (...) 
	{
        cout << "An unknown error occurred." << endl;
    }
}
int main() 
{
    
    mainFunction2();
    mainFunction1(); //program terminates abnormally in this case
    
}
