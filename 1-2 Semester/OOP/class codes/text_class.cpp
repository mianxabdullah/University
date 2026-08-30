#include<iostream>
using namespace std;
class text
{
	protected:
		char *s;
		int size;
		int capacity;
	public:
		void resize(int new_capacity)
		{
			char *new_s= new char[new_capacity];
			for(int i=0;i<size;i++)
			{
				new_s[i]=s[i];
			}
			delete[] s;
			s=new_s;
			capacity=new_capacity;
		}
		//default constructor
		text()
		{
			s= new char[1];
			this->capacity=1;
			size=0;
		}
		//paramerterized constructor
		text(const char *str)
		{
			for(size=0;str[size]!='\0';)  //to find size of parameter string
			{
				size++;
			}
			capacity=size+1;
			s=new char[capacity];
			
			for (int i = 0; i < size; i++) 
			{
                s[i] = str[i];
            }
            s[size] = '\0';
		}
		//copy constructor
		text(const text& other) 
		{
			size=other.size;
			capacity=other.capacity;
			
            s = new char[capacity];
            for (int i = 0; i <= size; i++) 
		    {
               s[i] = other.s[i];
            }
        }
        // Destructor
        ~text() 
		{
            delete[] s;
        }
        
        //Assignment operator
        text& operator=(const text&other)
        {
        	if(this!=&other)
        	{
        		delete[] s;
        		size=other.size;
			    capacity=other.capacity;
			
                s = new char[capacity];
                for (int i = 0; i <= size; i++) 
		        {
                    s[i] = other.s[i];
                }
			}
			return *this;
		}
		
		// Get current size
        int Size() const 
	    { 
	      return size; 
		}

       // Check if empty
        bool empty() const 
	    { 
	      return size == 0; 
		}

      // Safe character access
      char& at(int index) 
	  {
        if (index < 0 || index >= size) 
		{
            throw std::out_of_range("Index out of range");
        }
        return s[index];
      }

    // Unsafe character access
    char& operator[](int index) 
	{
        return s[index];
    }
    
    // Get C-style string
    const char* c_str() const   //to call use cout<<s1.c_str();
	{
        return s;
    }
    
    
    // Append another String
    void append(const text& str) 
	{
        if (size + str.size >= capacity - 1)  //resize if needed
		{
            resize(size + str.size + 1);
        }
        
        for (int i = 0; i < str.size; i++) 
		{
            s[size + i] = str.s[i];
        }
        
        size += str.size;
        s[size] = '\0';
    }
    
    // Append C-string
    void append(const char* str) 
	{
        int str_len = 0;
        while (str[str_len] != '\0') str_len++;  // finding length of string to be appended
        
        if (size + str_len >= capacity - 1)  //resize if needed
		{
            resize(size + str_len + 1);
        }
        
        for (int i = 0; i < str_len; i++) 
		{
            s[size + i] = str[i];
        }
        
        size += str_len;
        s[size] = '\0';
    }

    // Clear the string
    void clear() 
	{
        delete[] s;
        s = new char[1];
        s[0] = '\0';
        size = 0;
        capacity = 1;
    }

    // Add single character
    void push_back(char c) 
	{
        if (size + 1 >= capacity) 
		{
            resize(capacity * 2);
        }
        
        s[size] = c;
        size++;
        s[size] = '\0';
    }

    // String concatenation
    text operator+(const text& other) const 
	{
        text result(*this); //creating text object and storing this pointer in it
        result.append(other);
        return result;
    }

    // Comparison operators
    bool operator==(const text& other) const 
	{
        if (size != other.size) return false;
        
        for (int i = 0; i < size; i++) 
		{
            if (s[i] != other.s[i]) 
			{
                return false;
            }
        }
        return true;
    }

    bool operator!=(const text&other) const 
	{
        return !(*this == other);
    }

};

int main()
{
	text s1;                   // Empty string
    text s2 = "Hello";         // From C-string
    text s3 = s2;              // Copy constructor

    s2.append(" World");         // Append C-string
    s2.push_back('!');           // Add character

    text s4 = s2 + s3;         // Concatenation

    if (s2 == "Hello World!") 
	{  
	    cout<<"same"<<endl;
    }
 
    try 
	{
        char c = s2.at(100);     // Throws out_of_range
    } 
	catch (const std::out_of_range& e) 
	{
        std::cout << e.what() << std::endl;
    }
}