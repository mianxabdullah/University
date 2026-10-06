package showroom; 

public class sedan extends vehicles
{
	int id;
	
	public sedan(String m,String c,String b,String p,int i)
	{
		super(m,c,b,p);
		this.id=i;
	}
	
	public int getId()
	{
		return this.id;
	}
	
	public void setId(int i)
	{
		this.id=i;
	}
	
	@Override
	public void Show()
	{
		System.out.println("Sedan Id: "+id);
		super.Show();
	}
}