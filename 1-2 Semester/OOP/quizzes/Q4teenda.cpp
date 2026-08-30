/*Teendas are objects consisting of sequences of 3 or 5 integers, with the middle integer being
larger than those at the ends, and the left side being larger than the right side. For example,
<4, 5, 2>, <30, 200, 29>, <2000, 20000, 1>, <23, 35, 40, 30, 20> are teendas, while <1, 2, 3> is
not a teenda because the middle is not larger than the right, and <5, 9, 7> is not a teenda
because the left is not bigger than the right. <4, 5, 6, 1> is not a teenda as it does not consist of
3 or 5 integers but rather has 4, and <22, 12, 76, 15, 10> is also not a teenda.
It is worth noting that teendas are either composed of 3 or 5 integers. 3-integer teendas may
grow into 5-integer teendas, and 5-integer teendas may split into two 3-integer teendas as
spontaneous processes.
 
In the growing process, the values to be placed at the 2nd and 4th
positions are integer averages of the first two and last two values, respectively.
 In the splitting
process, half of the middle value goes to the first one as the 3rd value, and the other half goes
to the 2nd one as the 1st value.

 If, during the growth and split processes, the requirements of
the teenda class are not fulfilled, the new objects will die.
There is a member function of teenda objects named 'mutate' to grow or split depending on a
random number to simulate these spontaneous processes.
You need to describe (specify data members with their types and headers of the function
members) a class for the above-mentioned teenda objects. Later, in the main logic, create some
teenda objects, and then in a loop, mutate the objects. The main logic must display the
appropriate output of the activities happening*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Teenda {
private:
    int sequence[5];  // Maximum size needed (for 5-integer teendas)
    int size;         // Actual size (3 or 5)
    
    bool isValid() const {
        if (size != 3 && size != 5) return false;
        
        // Check middle is larger than ends
        int middle = sequence[size/2];
        if (middle <= sequence[0] || middle <= sequence[size-1]) return false;
        
        // Check left side is larger than right side
        if (sequence[0] <= sequence[size-1]) return false;
        
        // For 5-integer teendas, check the new positions
        if (size == 5) {
            if (sequence[1] != (sequence[0] + sequence[2]) / 2) return false;
            if (sequence[3] != (sequence[2] + sequence[4]) / 2) return false;
        }
        
        return true;
    }
    
    void grow() {
        if (size != 3) return;
        
        // Save original values
        int a = sequence[0], b = sequence[1], c = sequence[2];
        
        // Calculate new positions
        sequence[0] = a;
        sequence[1] = (a + b) / 2;
        sequence[2] = b;
        sequence[3] = (b + c) / 2;
        sequence[4] = c;
        size = 5;
        
        if (!isValid()) {
            // Revert if invalid
            sequence[0] = a;
            sequence[1] = b;
            sequence[2] = c;
            size = 3;
        }
    }
    
    bool split(Teenda& other) {
        if (size != 5) return false;
        
        // Save original values
        int a = sequence[0], b = sequence[1], c = sequence[2], 
            d = sequence[3], e = sequence[4];
        
        // Create first teenda (a, b, c/2)
        sequence[0] = a;
        sequence[1] = b;
        sequence[2] = c / 2;
        size = 3;
        
        // Create second teenda (c/2, d, e)
        other.sequence[0] = c / 2;
        other.sequence[1] = d;
        other.sequence[2] = e;
        other.size = 3;
        
        if (!isValid() || !other.isValid()) {
            // Revert if either is invalid
            sequence[0] = a;
            sequence[1] = b;
            sequence[2] = c;
            sequence[3] = d;
            sequence[4] = e;
            size = 5;
            return false;
        }
        
        return true;
    }
    
public:
    Teenda(const int* seq, int s) : size(s) {
        for (int i = 0; i < s; i++) sequence[i] = seq[i];
        if (!isValid()) size = 0;  // Mark as invalid
    }
    
    bool isAlive() const { return size > 0; }
    
    void mutate() {
        if (!isAlive()) return;
        
        if (size == 3) {
            grow();
        } 
        else if (size == 5) {
            Teenda newTeenda(nullptr, 0);
            if (split(newTeenda)) {
                cout << "Split successful! Created new Teenda: ";
                newTeenda.display();
            }
        }
    }
    
    void display() const {
        if (!isAlive()) {
            cout << "<DEAD>" << endl;
            return;
        }
        
        cout << "<";
        for (int i = 0; i < size; i++) {
            if (i > 0) cout << ", ";
            cout << sequence[i];
        }
        cout << ">" << endl;
    }
};

int main() {
    srand(time(0));
    
    // Create initial Teenda objects
    int seq1[] = {4, 5, 2};
    int seq2[] = {30, 200, 29};
    int seq3[] = {2000, 20000, 1};
    int seq4[] = {23, 35, 40, 30, 20};
    
    Teenda teendas[] = {
        Teenda(seq1, 3),
        Teenda(seq2, 3),
        Teenda(seq3, 3),
        Teenda(seq4, 5)
    };
    int teendaCount = 4;
    
    // Simulation loop
    for (int i = 0; i < 10; i++) {
        cout << "\n--- Iteration " << i + 1 << " ---" << endl;
        
        // Display current Teendas
        cout << "Current Teendas:" << endl;
        for (int j = 0; j < teendaCount; j++) {
            teendas[j].display();
        }
        
        // Mutate each Teenda
        for (int j = 0; j < teendaCount; j++) {
            cout << "Mutating: ";
            teendas[j].display();
            teendas[j].mutate();
        }
    }
    
    return 0;
}