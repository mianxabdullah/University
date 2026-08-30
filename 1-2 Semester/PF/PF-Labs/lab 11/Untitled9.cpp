#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int cols2 = mat2[0].size();

    
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> mat2 = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    if (mat1[0].size() != mat2.size()) {
        cout << "Matrix multiplication is not possible!" << endl;
        return 1;
    }

    vector<vector<int>> result = multiplyMatrices(mat1, mat2);

    cout << "Resultant Matrix:" << endl;
    displayMatrix(result);

    return 0;
}