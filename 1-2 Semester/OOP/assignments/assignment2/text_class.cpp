#include <iostream>
using namespace std;
class text {
protected:
    char *s;        // Dynamic character array to store the string
    int size;       // Current length of the string (excluding '\0')
    int capacity;   // Total allocated memory capacity

public:
    // Constructors & Destructor (Big Three)
    text();                         // Default constructor
    text(const char *str);          // Parameterized constructor
    text(const text& other);        // Copy constructor
    ~text();                        // Destructor

    // Assignment Operator (Big Three)
    text& operator=(const text& other);

    // Size & Capacity Operations
    int Size() const;               // Get current string length
    bool empty() const;             // Check if string is empty
    void resize(int new_capacity);  // Adjust memory capacity

    // Element Access
    char& at(int index);            // Safe access (with bounds checking)
    char& operator[](int index);    // Unsafe access (no bounds checking)
    const char& operator[](int index) const; // Const version
    const char* c_str() const;      // Get C-style string (null-terminated)

    // Modifiers
    void append(const text& str);    // Append another text object
    void append(const char* str);   // Append a C-string
    void clear();                   // Clear the string
    void push_back(char c);         // Add a single character

    // String Operations
    text operator+(const text& other) const; // Concatenation
    bool operator==(const text& other) const; // Equality check
    bool operator!=(const text& other) const; // Inequality check
    
    text substr(int start, int length) const;
    
    int find(const text& substr) const;      // Find substring
    int find(const char* substr) const;      // Find C-style substring
    int find(char c) const;                  // Find character
    
    void insert(int pos, const text& str);   // Insert text at position
    void insert(int pos, const char* str);   // Insert C-string at position
    void insert(int pos, char c);            // Insert character at position
    
    void erase(int pos, int len);            // Erase `len` chars from `pos`
    void pop_back();                         // Remove last character
    
    bool operator<(const text& other) const;  
    bool operator>(const text& other) const;
    bool operator<=(const text& other) const;
    bool operator>=(const text& other) const;
    
    friend ostream& operator<<(ostream& os, const text& t);
    friend istream& operator>>(istream& is, text& t);
    
    void reserve(int new_capacity);           // Reserve capacity without changing size
    void shrink_to_fit();                     // Reduce capacity to fit size
    
    void replace(int pos, int len, const text& str);  // Replace substring
    void replace(char old_char, char new_char);       // Replace all occurrences
    
    char* begin();                            // Iterator support
    char* end();
    const char* begin() const;
    const char* end() const;
    
};
//declaration of big three

//default constructor
text::text() : size(0), capacity(1) 
{
    s = new char[capacity];
    s[0] = '\0';  // Empty null-terminated string
}
//parameterized constructor
text::text(const char *str) 
{
    for (size = 0; str[size] != '\0'; size++);  // Compute length
    capacity = size + 1;
    s = new char[capacity];
    for (int i = 0; i < size; i++) s[i] = str[i];  // Copy characters
    s[size] = '\0';  // Null-terminate
}
//copy constructor
text::text(const text& other) : size(other.size), capacity(other.capacity) 
{
    s = new char[capacity];
    for (int i = 0; i <= size; i++) s[i] = other.s[i];  // Deep copy
}
//destructor
text::~text() 
{
    delete[] s;  // Free allocated memory
}
//copy assignment
text& text::operator=(const text& other) 
{
    if (this != &other) {  // Self-assignment check
        delete[] s;        // Free existing memory
        size = other.size;
        capacity = other.capacity;
        s = new char[capacity];
        for (int i = 0; i <= size; i++) s[i] = other.s[i];  // Deep copy
    }
    return *this;
}


int main()
{
	return 0;
}