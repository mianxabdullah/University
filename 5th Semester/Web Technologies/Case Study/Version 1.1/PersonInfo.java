import javax.swing.*;

public class PersonInfo {
    String name;
    String address;
    String phoneNum;

    // Parameterized constructor
    public PersonInfo(String n, String a, String p) {
        name = n;
        address = a;
        phoneNum = p;
    }

    // Method for displaying person record on GUI
    public void print() {
        JOptionPane.showMessageDialog(null, "name: " + name + " address: " + address + " phone no: " + phoneNum);
    }
}