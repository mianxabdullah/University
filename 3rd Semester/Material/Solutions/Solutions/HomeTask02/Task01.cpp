#include <iostream>
#include <fstream>
using namespace std;

class matrix2D
{
protected:
    int **data;
    int rows;
    int cols;
    int nonZeroCount;

public:
    matrix2D(int r = 0, int c = 0) : rows(r), cols(c), nonZeroCount(0)
    {
        if (rows < 0 || cols < 0)
            throw invalid_argument("Matrix dimensions cannot be negative");
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    matrix2D(const matrix2D &other) : rows(other.rows), cols(other.cols), nonZeroCount(other.nonZeroCount)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~matrix2D()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }

    matrix2D &operator=(const matrix2D &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }

        rows = other.rows;
        cols = other.cols;
        nonZeroCount = other.nonZeroCount;

        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    void setValue(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Matrix index  out of bounds");

        if (data[r][c] == 0 && val != 0)
            nonZeroCount++;
        if (data[r][c] != 0 && val == 0)
            nonZeroCount--;

        data[r][c] = val;
    }

    int getNonZeroCount() const { return nonZeroCount; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    int getValue(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Matrix index  out of bounds");

        return data[r][c];
    }

    int *operator[](int r)
    {
        if (r < 0 || r >= rows)
            throw out_of_range("Matrix index  out of bounds");

        return data[r];
    }

    const int *operator[](int r) const
    {
        if (r < 0 || r >= rows)
            throw out_of_range("Matrix index  out of bounds");

        return data[r];
    }

    void display()
    {
        cout << "Matrix " << rows << "x" << cols << " (Non-zero: " << nonZeroCount << "):\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void readFromFile(const string &filename)
    {
        // 1. Open the file
        ifstream file(filename);
        if (!file)
        {
            cout << "ERROR: Could not open file " << filename << endl;
            throw runtime_error("File open failed");
        }

        cout << "Reading matrix from: " << filename << endl;

        // 2. Read each row
        for (int i = 0; i < rows; i++)
        {
            cout << "Row " << i << ": ";

            // 3. Read each number in this row
            for (int j = 0; j < cols; j++)
            {
                int number;
                file >> number; // Read one number at a time

                if (file.fail())
                { // Check if reading failed
                    cout << "\nERROR: Could not read number at row " << i << ", col " << j << endl;
                    throw runtime_error("Invalid number in file");
                }

                // 4. Store the number in the matrix
                setValue(i, j, number);
                cout << number << " ";
            }
            cout << endl;
        }

        // 5. Close the file
        file.close();
        cout << "File reading completed successfully!" << endl << endl;
    }
};

class sparseMatrix
{
protected:
    matrix2D *matrix;

public:
};

int main()
{
    try
    {
        matrix2D m1(2, 3);
        m1.setValue(0, 2, 3);
        m1.setValue(0, 0, 1);
        m1.setValue(1, 0, 2);
        m1.display();
    }

    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}