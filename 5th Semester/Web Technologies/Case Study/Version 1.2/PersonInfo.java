import javax.swing.*;
import java.io.Serializable;

public class PersonInfo implements Serializable {
    // Unique ID for object serialization (optional but best practice)
    private static final long serialVersionUID = 1L;

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