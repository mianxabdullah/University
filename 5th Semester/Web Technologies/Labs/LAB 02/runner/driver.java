package runner;
import showroom.*;
import java.util.*;

public class driver
{
	public static void main(String[] args) 
	{
		vehicles[] v=new vehicles[4];
		v[0]= new sedan("M2012","Black","Toyota","2 Cr",1);
		v[1]= new sedan("M2008","Blue","Honda","1.2 Cr",2);
		v[2]= new suv("M2019","Red","Honda","6 million",3);
		v[3]= new suv("M1997","brown","bmw","4 million",4);
		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter 1 to see Sedan info OR " + "\nEnter 2 to see SUV info: ");
        int choice = in.nextInt();
		
		System.out.print("Your choice was: " +choice+ "\n");
		in.close();
		
		for(int i=0;i<4;i++)
		{
			if(choice == 1 && v[i] instanceof sedan)
			{
				v[i].Show();
			}
			
			else if(choice == 2 && v[i] instanceof suv)
			{
				v[i].Show();
			}
		}
		
	}
}