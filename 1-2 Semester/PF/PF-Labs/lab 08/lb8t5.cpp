#include<iostream>
#include<string>
#include<array>

using namespace std;
struct stud
{
	string name;
	int rollNO;
	float percent;


};

array<stud, 100> sortArray(array<stud, 100> a, int n);

int main()
{
	array<stud, 100> ar; 
	int n;
	cout<<"enter data size    ";
	cin>>n;
	int t=0;
	
	while (t<n)
	{cout<<"enter student name roll no and percentage"<<endl;
	    cin>>ar[t].name>>ar[t].rollNO>>ar[t].percent;
	  t++;
	}
	array<stud, 100> sar = sortArray(ar, n);
	int k = 0;
	while (k < n)
	{
		cout<<"student:"<<sar[k].name<<"    roll no:"<<sar[k].rollNO<<"   marks" << sar[k].percent << endl;
		k = k+1;
	}
	return 0;
}

array<stud, 100> sortArray(array<stud, 100> a, int n)
{
	array<stud, 100> r = a;
	int i = 0;
	while (i < n-1)
	{
		int sl = i;
		int j = i;
		while (j < n)
		{
			if (r[j].percent < r[sl].percent)
			{
				sl =j ;
			}
			j = j+1;
		}
				
		stud tmp = r[i];
		r[i] = r[sl];
		r[sl] = tmp;
		
		i = i+1;
	}
	
	return r;
}
