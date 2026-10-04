public class Employee
{
	String fname,lname,ssn;
	
	Employee(String F,String L,String S)
	{
		this.fname=F;
		this.lname=L;
		this.ssn=S;
	}
	
	@Override
	public String toString()
	{
		return String.format("Employee First Name: " +fname + " Employee Last Name: " +lname+ " Employee Social Security: "+ssn);
	}
	
	void earning()
	{
		System.out.println("earning() is in Employee Class");
	}
	
}