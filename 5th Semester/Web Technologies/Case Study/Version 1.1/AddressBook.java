import javax.swing.*;
import java.util.*;
import java.io.*;

class AddressBook {
    ArrayList persons;

    // Constructor - automatically loads existing records on startup
    public AddressBook() {
        persons = new ArrayList();
        loadPersons();
    }

    // Add new person record to arraylist after taking input
    public void addPerson() {
        String name = JOptionPane.showInputDialog("Enter name");
        String add = JOptionPane.showInputDialog("Enter address");
        String pNum = JOptionPane.showInputDialog("Enter phoneNo");
        
        // Construct new person object and add to arraylist
        PersonInfo p = new PersonInfo(name, add, pNum);
        persons.add(p);
    }

    // Search person record by name
    public void searchPerson(String n) {
        for (int i = 0; i < persons.size(); i++) {
            PersonInfo p = (PersonInfo) persons.get(i);
            if (n.equals(p.name)) {
                p.print();
            }
        }
    }

    // Delete person record by name
    public void deletePerson(String n) {
        for (int i = 0; i < persons.size(); i++) {
            PersonInfo p = (PersonInfo) persons.get(i);
            if (n.equals(p.name)) {
                persons.remove(i);
            }
        }
    }

    // Load persons from persons.txt file on startup
    public void loadPersons() {
        String tokens[] = null;
        String name, add, ph;
        try {
            FileReader fr = new FileReader("persons.txt");
            BufferedReader br = new BufferedReader(fr);
            String line = br.readLine();
            while (line != null) {
                tokens = line.split(",");
                name = tokens[0];
                add = tokens[1];
                ph = tokens[2];
                PersonInfo p = new PersonInfo(name, add, ph);
                persons.add(p);
                line = br.readLine();
            }
            br.close();
            fr.close();
        } catch (IOException ioEx) {
            System.out.println(ioEx);
        }
    }

    // Save persons to persons.txt file on application exit
    public void savePersons() {
        try {
            PersonInfo p;
            String line;
            FileWriter fw = new FileWriter("persons.txt");
            PrintWriter pw = new PrintWriter(fw);
            for (int i = 0; i < persons.size(); i++) {
                p = (PersonInfo) persons.get(i);
                line = p.name + "," + p.address + "," + p.phoneNum;
                // Writes line to file (persons.txt)
                pw.println(line);
            }
            pw.flush();
            pw.close();
            fw.close();
        } catch (IOException ioEx) {
            System.out.println(ioEx);
        }
    }
}