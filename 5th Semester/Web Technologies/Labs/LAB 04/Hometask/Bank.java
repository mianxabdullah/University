import java.io.*;
import java.util.*;

class noAccountAvailbaleException extends Exception
{
    noAccountAvailbaleException(String msg)
    {
        super(msg);
    }
}

public class Bank
{
    private String name;
    private String accountNumber;
    private double amount;

    public Bank()
    {
        name = "";
        accountNumber = "";
        amount = 0;
    }

    public Bank(String n, String an, double a)
    {
        name = n;
        accountNumber = an;
        amount = a;
    }

    public String getName() { return name; }
    public String getAccountNumber() { return accountNumber; }
    public double getAmount() { return amount; }

    public void setName(String n) { name = n; }
    public void setAccountNumber(String an) { accountNumber = an; }
    public void setAmount(double a) { amount = a; }

    // Add new account
    public void addNewRecord() throws IOException
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name: ");
        name = sc.nextLine();

        System.out.print("Enter 8 digit account number: ");
        accountNumber = sc.nextLine();

        if (!accountNumber.matches("\\d{8}"))
        {
            System.out.println("Invalid account number!");
            return;
        }

        if (findAccount(accountNumber) != null)
        {
            System.out.println("Account already exists!");
            return;
        }

        amount = 1000;

        BufferedWriter out = new BufferedWriter(
            new FileWriter("accounts.txt", true));

        out.write(name + ";" + accountNumber + ";" + amount);
        out.newLine();
        out.close();

        System.out.println("Account created successfully!");
    }

    // Find account
    public static Bank findAccount(String no) throws IOException
    {
        File f = new File("accounts.txt");

        if (!f.exists())
            return null;

        BufferedReader in = new BufferedReader(new FileReader(f));
        String s;

        while ((s = in.readLine()) != null)
        {
            String data[] = s.split(";");

            if (data.length == 3 && data[1].trim().equals(no))
            {
                Bank b = new Bank(data[0].trim(),
                    data[1].trim(),
                    Double.parseDouble(data[2].trim()));

                in.close();
                return b;
            }
        }

        in.close();
        return null;
    }

    // Transfer money
    public static void transfer(String senderNo, String receiverNo,
                                double money)
        throws IOException, noAccountAvailbaleException
    {
        Bank sender = findAccount(senderNo);
        Bank receiver = findAccount(receiverNo);

        if (receiver == null)
            throw new noAccountAvailbaleException("Recipient not found!");

        if (sender == null || senderNo.equals(receiverNo) ||
            money <= 0 || sender.amount < money)
        {
            System.out.println("Invalid transfer!");
            return;
        }

        sender.amount -= money;
        receiver.amount += money;

        File temp = new File("temp.txt");
        BufferedReader in = new BufferedReader(new FileReader("accounts.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter(temp));

        String s;

        while ((s = in.readLine()) != null)
        {
            String data[] = s.split(";");

            if (data.length == 3 && data[1].trim().equals(senderNo))
                out.write(sender.name + ";" + senderNo + ";" + sender.amount);
            else if (data.length == 3 && data[1].trim().equals(receiverNo))
                out.write(receiver.name + ";" + receiverNo + ";" + receiver.amount);
            else
                out.write(s);

            out.newLine();
        }

        in.close();
        out.close();

        File old = new File("accounts.txt");

        if (old.delete() && temp.renameTo(old))
            System.out.println("Transfer successful!");
        else
            System.out.println("Error updating file!");
    }

    // Main menu
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int choice = 0;

        do
        {
            System.out.println("\n1. Add New Account");
            System.out.println("2. Transfer");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");

            try
            {
                choice = Integer.parseInt(sc.nextLine());

                switch (choice)
                {
                    case 1:
                        new Bank().addNewRecord();
                        break;

                    case 2:
                        System.out.print("Sender account number: ");
                        String sender = sc.nextLine();

                        System.out.print("Recipient account number: ");
                        String receiver = sc.nextLine();

                        System.out.print("Amount: ");
                        double money = Double.parseDouble(sc.nextLine());

                        transfer(sender, receiver, money);
                        break;

                    case 3:
                        System.out.println("Goodbye!");
                        break;

                    default:
                        System.out.println("Invalid choice!");
                }
            }
            catch (noAccountAvailbaleException e)
            {
                System.out.println(e.getMessage());
            }
            catch (IOException e)
            {
                System.out.println("File error: " + e.getMessage());
            }
            catch (NumberFormatException e)
            {
                System.out.println("Invalid number!");
            }
        }
        while (choice != 3);

        sc.close();
    }
}
