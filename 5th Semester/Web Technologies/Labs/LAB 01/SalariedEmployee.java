import java.util.*;
public class SalariedEmployee extends Employee
{
	double weeklySalary;
	
	SalariedEmployee(String f,String l,String s,double w)
	{
		super(f,l,s);
		weeklySalary=w;
	}
	
	@Override
	public String toString()
	{
		super.toString();
		return String.format("SalariedEmployee Weekly Salary: "+weeklySalary);
	}
	
	@Override
	void earning()
	{
		System.out.println("SalariedEmployee Weekly Salary: "+weeklySalary);
	}
	
}