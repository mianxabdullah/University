import javax.swing.*;

class Test {
    public static void main(String args[]) {
        AddressBook ab = new AddressBook();
        String input, s;
        int ch;

        while (true) {
            input = JOptionPane.showInputDialog("Enter 1 to add " + "\nEnter 2 to Search \nEnter 3 to Delete" + "\nEnter 4 to Exit");
            
            if (input == null) {
                ab.savePersons();
                System.exit(0);
            }

            ch = Integer.parseInt(input);

            switch (ch) {
                case 1:
                    ab.addPerson();
                    break;

                case 2:
                    s = JOptionPane.showInputDialog("Enter name to search ");
                    if (s != null) ab.searchPerson(s);
                    break;

                case 3:
                    s = JOptionPane.showInputDialog("Enter name to delete ");
                    if (s != null) ab.deletePerson(s);
                    break;

                case 4:
                    ab.savePersons();
                    System.exit(0);
            }
        }
    }
}