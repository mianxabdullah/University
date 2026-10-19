import java.io.*;
import javax.swing.*;
import java.util.*;

public class FileCopy 
{
    private static void doCopy(String src,String dest) 
	{
        try
		{
            File srcFile = new File(src);
			File destFile = new File(dest);
			
			boolean s_exists = srcFile.exists();
			boolean d_exists = destFile.exists();
			
			if (! s_exists) 
			{
                throw new FileNotFoundException(); 
            }
			
			if (! d_exists) 
			{
                throw new FileNotFoundException();
            }
			
			BufferedReader in = new BufferedReader(new FileReader(src));
			BufferedWriter out = new BufferedWriter(new FileWriter(dest));
			
			String s; 
            while((s = in.readLine()) != null) 
			{ 
				out.write(s);
				out.write('\n');
           	}
				
			System.out.println("File Copied Successfully from "+src+" to "+dest);
            
			in.close();
            out.close();
        } 
		catch (FileNotFoundException f) 
		{

            System.out.println("FileNotFound: ");
            f.printStackTrace();
        }
		catch (IOException e) 
		{

            System.out.println("IOException:");
            e.printStackTrace();
        }

    }

	public static void main(String args[]) 
	{	
		String src = JOptionPane.showInputDialog("Enter the path or name of an existing source file ");
		String dest = JOptionPane.showInputDialog("Enter the path or name of the destination file");
		doCopy(src,dest);
		System.exit(0);
    }

}

 
