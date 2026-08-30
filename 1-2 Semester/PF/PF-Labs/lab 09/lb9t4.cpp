#include <iostream>
#include <array>
#include <string>
using namespace std;
void first(int n);
void second(int n);
void third(int n);
void forth(int n);
void fifth (int n);
void sixth (int n);
void first(int n)
{ for(int i=1;i<=n;i++)
  { for(int j=1;j<=i;j++)
    { 
      cout<<j;
	}
	cout<<endl;
  }
}
  void second(int n)
{
  for(int i=1;i<=n;i++)
  { 
    for(int j=1;j<=i;j++)
    { 
      cout<<"*";
	}
	cout<<endl;
  }
}
 void third(int n)
{
  for(int i=n;i>=1;i--)
  { 
    for(int j=i;j>=1;j--)
    { 
      cout<<"X";
	}
	cout<<endl;
  }
}
void forth(int n)
{
  for(int i=1;i<=n;i++)
  { int x=1;
    int j;
    for( j=1;j<=i;j++)
    { 
      cout<<x;
      x++;
	}
	for(int k=j-2;k>=1;k--)
	{ cout<<k;
	}
	cout<<endl;
  }
}
void fifth (int n)
{ for(int i=1;i<=n;i++)
  { for(int j=1;j<=i;j++)
    { 
      cout<<j;
	}
	cout<<endl;
  }
  cout<<endl;
  for(int i=n;i>=1;i--)
  { int k=1;
    for(int j=i;j>=1;j--)
    { 
      cout<<k;
      k++;
	}
	cout<<endl;
  }

}
void sixth (int n)
{
	for(int i=n;i>=1;i--)
  { int k=0;
    for(int j=i;j>=1;j--)
    {  
	  cout<<" ";
	  k++;
    }
    cout<<k;
    
	cout<<endl;
  }
}

int main()
{ 
 int n;
 cout<<"enter a number";
 cin>>n;
 first(n);
 second(n);
 third(n);
 forth(n);
 fifth(n);
 sixth(n);
}