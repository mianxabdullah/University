#include<iostream>
using namespace std;
//02468
//01234
bool isGoodNum(string& s,int index)
{
    if(index>=s.length())
        return true;
    if(index%2==0 && (s[index]-'0')%2!=0)
    {
        return false;
    }
    if(index%2!=0)
    {
        if ((s[index]-'0') < 2) return false; 
        int i=2;
        while(i<(s[index]-'0'))
        {
            if((s[index]-'0')%i==0)
            {
                return false;
            }
            i++;
        }
    }
    return isGoodNum(s,index+1);
}
int main()
{
    string strArr[] = {"02468", "23478", "224365"}; 
    for (string digits : strArr) 
    { 
        bool is_good = isGoodNum(digits, 0); 
        cout << "Digit string:" << digits 
        <<" is " <<(is_good ? "good" :"not good") << endl;
    }
}
