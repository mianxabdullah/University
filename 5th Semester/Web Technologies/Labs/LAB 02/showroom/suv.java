package showroom; 

public class suv extends vehicles
{
	int sid;
	
	public suv(String m,String c,String b,String p,int i)
	{
		super(m,c,b,p);
		this.sid=i;
	}
	
	public int getId()
	{
		return this.sid;
	}
	
	public void setId(int i)
	{
		this.sid=i;
	}
	
	@Override
	public void Show()
	{
		System.out.println("SUV Id: "+sid);
		super.Show();
	}
}