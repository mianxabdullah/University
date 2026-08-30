#include<iostream>
using namespace std;
int freq(int d, int n)
{
	int f = 0;
	int dig;
	while(n != 0)
	{
		dig = n % 10;
		if(dig == d)
		{
			f = f + 1;
    	}
		n = n / 10;
	}
		return f;
}
int main()
{
	int n;
	int f0 = 0;
	int f1 = 0;
	int f2 = 0;
	int f3 = 0;
	int f4 = 0;
	int f5 = 0;
	int f6 = 0;
	int f7 = 0;
	int f8 = 0;
	int f9 = 0;
	cout << "Enter a number : ";
	cin >> n;
	cout << "	0	1	2	3	4	5	6	7	8	9" << endl;
	cout << endl;
	int i = 0;
	while(i <= n)
	{
		f0 = f0 + freq(0, i);
        f1 = f1 + freq(1, i);
        f2 = f2 + freq(2, i);
        f3 = f3 + freq(3, i);
        f4 = f4 + freq(4, i);
        f5 = f5 + freq(5, i);
        f6 = f6 + freq(6, i);
        f7 = f7 + freq(7, i);
        f8 = f8 + freq(8, i);
        f9 = f9 + freq(9, i);
		cout << i << ":	" << f0 << " 	"<< f1 << "	"<< f2 << "	" << f3 <<"	" << f4 <<"	" << f5 <<"	" << f6 << "	" << f7 << "	" << f8 << "	" << f9;
		cout << endl;
		i++;
		}
	}