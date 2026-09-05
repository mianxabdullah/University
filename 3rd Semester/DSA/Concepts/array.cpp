
//Row-major 2D: A[i][j]=Base + ( i×cols + j) × sizeof(type)
//Col-major 2D: A[i][j]=Base + ( j×rows + i) × sizeof(type)
//Address(A[i][j][k]) = Base + ((i * D2 * D3) + (j * D3) + k) * sizeof(type)
//Address(A[i][j][k]) = Base + ((k * D1 * D2) + (j * D1) + i) * sizeof(type)

#include <iostream>
using namespace std;

int main() {
    int A[2][3][4] = {
        { {  1,  2,  3,  4 },
          {  5,  6,  7,  8 },
          {  9, 10, 11, 12 } },

        { { 13, 14, 15, 16 },
          { 17, 18, 19, 20 },
          { 21, 22, 23, 24 } }
    };

    int i = 1, j = 1, k = 2;

    cout << "Normal access: " << A[i][j][k] << endl;

    cout << "Pointer arithmetic: " 
         << *(*(*(A + i) + j) + k) << endl;

     *(*(*(A + i) + j) + k)=69;
     cout << "Pointer arithmetic: " 
     << *(*(*(A + i) + j) + k) << endl;

     cout << "Flattened access: " 
          << *(&A[0][0][0] + (i*3*4 + j*4 + k)) << endl;
     // MODIFIED:
     *(&A[0][0][0] + (i*3*4 + j*4 + k))=99;
     cout << "Flattened access: " 
          << *(&A[0][0][0] + (i*3*4 + j*4 + k)) << endl;

     return 0;
}