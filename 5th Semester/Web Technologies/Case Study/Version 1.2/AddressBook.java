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

    // Version 1.2: Deserialization - Load ArrayList directly from file
    @SuppressWarnings("unchecked")
    public void loadPersons() {
        try {
            FileInputStream fis = new FileInputStream("persons.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);

            // Read the entire ArrayList object directly
            persons = (ArrayList) ois.readObject();

            ois.close();
            fis.close();
        } catch (FileNotFoundException e) {
            System.out.println("No existing data file found. Starting with an empty address book.");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading data: " + e);
        }
    }

    // Version 1.2: Serialization - Save ArrayList directly to file
    public void savePersons() {
        try {
            FileOutputStream fos = new FileOutputStream("persons.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            // Write the entire ArrayList object directly
            oos.writeObject(persons);

            oos.flush();
            oos.close();
            fos.close();
        } catch (IOException e) {
            System.out.println("Error saving data: " + e);
        }
    }
}