public class BaseCommEmployee extends CommissionEmployee
{
	double baseSal;
	
	BaseCommEmployee(String f,String l,String s,double g,double cr,double bs)
	{
		super(f,l,s,g,cr);
		baseSal=bs;
	}
	
	@Override
	public String toString()
	{
		super.toString();
		return String.format("BaseCommEmployee Base Salary: " + baseSal);
	}
	
	@Override
	void earning()
	{
		System.out.println("BaseCommEmployee Earning: " + ((commRate*grossSalary)+baseSal));
	}
	
}