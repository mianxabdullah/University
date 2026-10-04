public class Test
{
	public static void main(String[] agrgs)
	{
		Employee[] e = new Employee[10];
		e[0]= new Employee("haseeb","ahmad","pk123456789");
		e[1]= new Employee("sufiyan","ahmad","pk987654321");
		e[2]= new SalariedEmployee("Ahad","Ali","pk12345609",5000);
		e[3]= new SalariedEmployee("Ahmad","Pervaiz","pk56789098",4000);
		e[4]= new HourlyEmployee("Huzaifa","ali","pk9812345",6,450.7);
		e[5]= new HourlyEmployee("Zuhaib","ali","pk98123890",8,348.00);
		e[6]= new CommissionEmployee("zain","ahmad","pk57543456",500000,0.1);
		e[7]= new CommissionEmployee("samiq","abbas","pk57543123",450000,3);
		e[8]= new BaseCommEmployee("fahad","ali","pk45678987654",500000,0.1,23000);
		e[9]= new BaseCommEmployee("babar","azam","pk5243422",450000,3,67000);
		
		for(int i=0;i<10;i++)
		{
			System.out.println(e[i].toString());
			e[i].earning();
		}
	}
}