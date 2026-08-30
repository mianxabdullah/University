#include <iostream>
using namespace std;

template <typename T>
T accumulate(T arr[], int size) 
{
    T sum = 0;
    for (int i = 0; i < size; i++) 
	{
        sum = sum+arr[i];
    }
    return sum;
}

int main() 
{
    int intArr[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArr) / sizeof(intArr[0]); //sizeof return no of bytes not size of array
    cout << "Sum of int array: " << accumulate(intArr, intSize) << endl;

    double doubleArr[] = {1.1098, 2.2665, 3.3899, 4.47787, 5.556};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Sum of double array: " << accumulate(doubleArr, doubleSize) << endl;

    float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Sum of float array: " << accumulate(floatArr, floatSize) << endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "Sum of char array: " << accumulate(charArr, charSize) << endl;

    bool boolArr[] = {true, false, true, false, true};
    int boolSize = sizeof(boolArr) / sizeof(boolArr[0]);
    cout << "Sum of bool array: " << accumulate(boolArr, boolSize) << endl;

    return 0;
}
