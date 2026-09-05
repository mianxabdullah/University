#include <iostream>
#include <vector>
using namespace std;

int findFirstNonRepeating(vector<int>& v) {
    int size = 1000;
    int max = 2001; 
    
    //vector<int> res(max,0);
    int res[max];
    for(int i = 0; i < max; i++) {
        res[i]=0;
    }
    
    for (int n : v) 
    {
        res[n+size]+=1;
    }
    
    for (int n : v) {
        if (res[n + size] == 1) {
            return n;
        }
    }
    return -1;
}

int main() {
    // Sample 1
    vector<int> sample1 = {4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6};
    cout << "Sample 1:" << endl;
    cout << "Input: 4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6" << endl;
    cout << "Output: " << findFirstNonRepeating(sample1) << endl;
    cout << "Expected: 7" << endl << endl;
    
    // Sample 2
    vector<int> sample2 = {1, 5, 2, 5, 4, 1, 2, 3, 4, 3, 5};
    cout << "Sample 2:" << endl;
    cout << "Input: 1, 5, 2, 5, 4, 1, 2, 3, 4, 3, 5" << endl;
    cout << "Output: " << findFirstNonRepeating(sample2) << endl;
    cout << "Expected: -1" << endl << endl;
    
    // Additional test cases
    vector<int> test3 = {1, 2, 3, 4, 5};
    cout << "Test 3 (all unique):" << endl;
    cout << "Input: 1, 2, 3, 4, 5" << endl;
    cout << "Output: " << findFirstNonRepeating(test3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> test4 = {1, 1, 1, 1};
    cout << "Test 4 (all same):" << endl;
    cout << "Input: 1, 1, 1, 1" << endl;
    cout << "Output: " << findFirstNonRepeating(test4) << endl;
    cout << "Expected: -1" << endl << endl;
    
    vector<int> test5 = {-1000, 0, 1000, -1000, 0, 1000};
    cout << "Test 5 (edge range values):" << endl;
    cout << "Input: -1000, 0, 1000, -1000, 0, 1000" << endl;
    cout << "Output: " << findFirstNonRepeating(test5) << endl;
    cout << "Expected: -1" << endl;
    
    return 0;
}
