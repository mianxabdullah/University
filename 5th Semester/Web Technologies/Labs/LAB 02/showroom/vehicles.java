package showroom; 

public class vehicles
{
	String model, color, brand, price;
	
	public vehicles(String m,String c,String b,String p)
	{
		this.model=m;
		this.color=c;
		this.brand=b;
		this.price=p;
	}
	
	public String getModel()
	{
		return this.model;
	}
	
	public void setModel(String m)
	{
		this.model=m;
	}
	
	public String getColor()
	{
		return this.color;
	}
	
	public void setColor(String c)
	{
		this.color=c;
	}
	
	public String getBrand()
	{
		return this.brand;
	}
	
	public void setBrand(String b)
	{
		this.brand=b;
	}
	
	public String getPrice()
	{
		return this.price;
	}
	
	public void setprice(String p)
	{
		this.price=p;
	}
	
	public void Show()
	{
		System.out.println("Model: " + model + " Color: "+color+" Brand: "+brand+" Price: "+price);
	}
	
}