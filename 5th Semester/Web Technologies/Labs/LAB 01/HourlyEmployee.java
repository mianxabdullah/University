public class HourlyEmployee extends Employee
{
	int hours;
	double wages;
	
	HourlyEmployee(String f,String l,String s,int h,double w)
	{
		super(f,l,s);
		wages=w;
		hours=h;
	}
	
	@Override
	public String toString()
	{
		super.toString();
		return String.format("HourlyEmployee Wages: " + wages + " HourlyEmployee Working Hours: " +hours);
	}
	
	@Override
	void earning()
	{
		if(hours<=40)
		{
			System.out.println("HourlyEmployee Earing: " + hours*wages );
		}
		else
		{
			System.out.println("HourlyEmployee Earing: " +  (40*wages) + ((hours-40)* (wages*1.5)) );
		}
	}
	
}