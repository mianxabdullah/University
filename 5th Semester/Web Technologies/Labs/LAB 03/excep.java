import java.io.*;
import java.util.*;

class NegNumExcep extends Exception
{
	int n;

	public NegNumExcep (int num)
	{  
		n = num;    
	}

	public String toString()
	{
		return "You entered a negative numbe: " + n ;
	}
}

class TooLargeNumExcep extends Exception
{
	int n;

	public TooLargeNumExcep (int num)
	{  
		n = num;    
	}

	public String toString()
	{
		return "You entered a TooLargeNum: " + n ;
	}
}

public class excep
{
	public static boolean is_prime(int n) throws NegNumExcep, TooLargeNumExcep
	{
		if(n>50)
		{
			throw new TooLargeNumExcep(n);
		}
		else if(n<0)
		{
			throw new NegNumExcep(n);
		}
		else if(n==0 || n==1)
		{
			return true;
		}
		else
		{
			for(int i=2;i<n;i++)
			{
				if(n%i==0)
				{
					return false;
				}
			}
			return true;
		}
	}

	public static void main(String [] args)
	{
		System.out.print("Enter a Number to check if its Prime: ");
		Scanner in = new Scanner(System.in);
		int x = in.nextInt();
		try
		{
				boolean z = is_prime(x);
				if(z==true)
				{
					System.out.println(x+ " is a Prime Number");
				}
				else
				{
					System.out.println(x+ " is not a Prime Number");
				}
		}
		
		catch (NegNumExcep n)
		{
			System.out.println("Error: " +n.toString());
		}
		
		catch (TooLargeNumExcep l)
		{
			System.out.println("Error: "+ l.toString());
		}
		
		catch(Exception e)
		{
			System.out.println("Error: " + e.toString());
		}
			
	}
}

