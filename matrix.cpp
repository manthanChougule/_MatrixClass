// #include<iostream>
// #include<math.h>
// #include<iomanip>
// #include <fstream>
// #include <cstring>
#include <bits/stdc++.h>
#include <iostream>
#include "matrix.hpp"

using namespace std;

matrix::matrix()
{
    string inputString;
    fstream file;
    file.open("input.txt", ios::in);
    if (file)
    {
        // this is done for taking row and col from file
        getline(file, inputString);
        stringstream is(inputString);
        string firstLine;
        int array[2];
        int i = 0;
        while (is >> firstLine)
        {
            array[i] = stoi(firstLine);
            i++;
        }
        row_ = array[0];
        col_ = array[1];
        // create matirx of row and col given in inputfile
        matrixCreate();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    if (file)
    {
        int counter = 0;
        while (!file.eof())
        {
            getline(file, inputString);
            stringstream is(inputString);
            string matrixLine;
            int i = 0;
            while (is >> matrixLine)
            {
                mat_[counter][i] = stof(matrixLine);
                i++;
            }
            counter++;
        }
        // printMatrix();
        // displayMatrix();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    file.close();
}

void matrix::matrixCreate()
{
    // creating matrix
    mat_ = new double *[getRow()];
    for (int i = 0; i < getRow(); i++)
    {
        mat_[i] = new double[getCol()];
    }
}

void matrix::setter(const int row, const int col)
{
    // setting row and col
    row_ = row;
    col_ = col;
}

inline int matrix::getRow(void) const
{
    return row_;
}

inline int matrix::getCol(void) const
{
    return col_;
}

void matrix::printMatrix()
{
    // printing matrix in output file
    fstream file;
    file.open("output.txt", ios::out);
    for (int i = 0; i < getRow(); i++)
    {
        for (int j = 0; j < getCol(); j++)
        {
            file << mat_[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void matrix::displayMatrix()
{
    // displaying matrix at terminal
    for (int i = 0; i < getRow(); i++)
    {
        for (int j = 0; j < getCol(); j++)
        {
            cout << setw(8) << mat_[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix::cmdInput()
{
    // taking inout from cmd (command prompt or user)
    for (int i = 0; i < getRow(); i++)
    {
        for (int j = 0; j < getCol(); j++)
        {
            cout << "Enter (" << i << ", " << j << ") element :";
            cin >> mat_[i][j];
        }
    }
}

// method overloadings

void matrix::printMatrix(char filename[50])
{
    fstream file;
    file.open(filename, ios::out);
    if (file)
    {
        for (int i = 0; i < getRow(); i++)
        {
            for (int j = 0; j < getCol(); j++)
            {
                file << mat_[i][j] << " ";
            }
            file << endl;
        }
    }
    else
    {
        cout << "Error in Opening output file " << endl;
    }
    file.close();
}

matrix::matrix(char filename[20])
{
    string inputString;
    fstream file;
    file.open(filename, ios::in);
    if (file)
    {
        // this is done for taking row and col from file
        getline(file, inputString);
        stringstream is(inputString);
        string firstLine;
        int array[2];
        int i = 0;
        while (is >> firstLine)
        {
            array[i] = stoi(firstLine);
            i++;
        }
        row_ = array[0];
        col_ = array[1];
        // create matirx of row and col given in inputfile
        matrixCreate();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    if (file)
    {
        int counter = 0;
        while (!file.eof())
        {
            getline(file, inputString);
            stringstream is(inputString);
            string matrixLine;
            int i = 0;
            while (is >> matrixLine)
            {
                mat_[counter][i] = stof(matrixLine);
                i++;
            }
            counter++;
        }
        // this->printMatrix();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    file.close();
}

matrix::matrix(int row, int col)
{
    setter(row, col);
    matrixCreate();
    // displayMatrix();
}

matrix::matrix(int row, int col, char filename[50])
{
    // this method need differnt inputfile type
    setter(row, col);
    matrixCreate();
    string inputString;
    fstream file;
    file.open(filename, ios::in);
    if (file)
    {
        int counter = 0;
        while (!file.eof())
        {
            getline(file, inputString);
            stringstream is(inputString);
            string matrixLine;
            int i = 0;
            while (is >> matrixLine)
            {
                mat_[counter][i] = stof(matrixLine);
                i++;
            }
            counter++;
        }
        // printMatrix();
        // displayMatrix();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    file.close();
}

matrix::matrix(int row)
{
    setter(row, row);
    matrixCreate();
    // displayMatrix();
}

matrix::matrix(int row, char filename[50])
{
    // square matrix with input taking from file
    setter(row, row);
    matrixCreate();
    string inputString;
    fstream file;
    file.open(filename, ios::in);
    if (file)
    {
        int counter = 0;
        while (!file.eof())
        {
            getline(file, inputString);
            stringstream is(inputString);
            string matrixLine;
            int i = 0;
            while (is >> matrixLine)
            {
                mat_[counter][i] = stof(matrixLine);
                i++;
            }
            counter++;
        }
        // printMatrix();
        displayMatrix();
    }
    else
    {
        cout << "Error in input file " << endl;
    }
    file.close();
}

matrix::matrix(matrix &M) : row_(M.getRow()), col_(M.getRow())
{
    // coping matrix from another matrix
    matrixCreate();
    for (int i = 0; i < row_; i++)
    {
        for (int j = 0; j < col_; j++)
        {
            mat_[i][j] = M.mat_[i][j];
        }
    }
}

// operator overloading

matrix &matrix::operator=(const matrix M)
{ // operator =
    // this is same as copy matrix
    setter(M.getRow(), M.getCol());
    matrixCreate();
    // copy matrix content
    for (int i = 0; i < row_; i++)
    {
        for (int j = 0; j < col_; j++)
        {
            mat_[i][j] = M.mat_[i][j];
        }
    }
    return (*this);
}

matrix matrix::operator+(matrix &M) const
{
    // operator +
    matrix ans;
    ans.setter(M.getRow(), M.getCol());
    ans.matrixCreate();
    for (int i = 0; i < ans.getRow(); i++)
    {
        for (int j = 0; j < ans.getCol(); j++)
        {
            ans.mat_[i][j] = this->mat_[i][j] + M.mat_[i][j];
        }
    }
    return ans;
}

matrix matrix::operator-(matrix &M) const
{
    // operator -
    matrix ans;
    ans.setter(M.getRow(), M.getCol());
    ans.matrixCreate();
    for (int i = 0; i < ans.getRow(); i++)
    {
        for (int j = 0; j < ans.getCol(); j++)
        {
            ans.mat_[i][j] = this->mat_[i][j] - M.mat_[i][j];
        }
    }
    return ans;
}

matrix matrix::operator*(matrix &M) const
{
    // operator *
    if (this->getCol() == M.getRow())
    {
        matrix ans;
        // row of 1st mat and col of 2nd mat
        ans.setter(this->getRow(), M.getCol());
        ans.matrixCreate();

        for (int i = 0; i < ans.getRow(); i++)
        {
            for (int j = 0; j < ans.getCol(); j++)
            {
                // this is for non square matrix too
                for (int k = 0; k < this->getCol(); k++)
                {
                    ans.mat_[i][j] += this->mat_[i][k] * M.mat_[k][j];
                }
            }
        }
        return ans;
    }
    else
    {
        cout << "Cannot multiply these matrix !!! 1st matrix col and 2nd matrix row don't match !!!" << endl;
        exit(0);
    }
}

ostream &operator<<(ostream &output, const matrix &M)
{
    // operator <<
    output << "row = " << M.getRow() << ", col = " << M.getCol() << endl;
    output << endl;
    output << " Matrix " << endl;
    output << endl;
    for (int i = 0; i < M.getRow(); i++)
    {
        for (int j = 0; j < M.getCol(); j++)
        {
            output << setw(8) << M.mat_[i][j];
        }
        output << endl;
    }
    return output;
}

istream &operator>>(istream &input, matrix &M)
{
    // operator >>
    cout << "Enter Row and Col " << endl;
    input >> M.row_;
    input >> M.col_;
    M.matrixCreate();

    cout << "Enter the content of matrix " << endl;
    for (int i = 0; i < M.getRow(); i++)
    {
        cout << "Enter element of " << i << "th row" << endl;
        for (int j = 0; j < M.getCol(); j++)
        {
            // cout << "Enter element of (" << i << ", "<< j <<")th position ." << endl;
            input >> M.mat_[i][j];
        }
    }
    return input;
}

// scalar multiplication and division
void matrix::scalarMultiplication(double num)
{
    // multiplication
    for (int i = 0; i < this->getRow(); i++)
    {
        for (int j = 0; j < this->getCol(); j++)
        {
            this->mat_[i][j] *= num;
        }
    }
}

void matrix::scalarDivision(double num)
{
    // scalar division
    for (int i = 0; i < this->getRow(); i++)
    {
        for (int j = 0; j < this->getCol(); j++)
        {
            this->mat_[i][j] /= num;
        }
    }
}

/* --------------------6) Member Functions (true/false)-------------------- */
bool matrix::isDiagonalDominant()
{
    // checking if matrix is diagonally dominant or not
    // (m25.isDiagonalDominant()) ? (cout << "Yes \n") : (cout << "No \n");
    for (int i = 0; i < this->getRow(); i++)
    {
        int sum = 0;
        for (int j = 0; j < this->getCol(); j++)
        {
            sum += abs(this->mat_[i][j]); 
        }
        sum -= abs(this->mat_[i][i]);
        // cout << sum << endl;
        if(abs(this->mat_[i][i]) < sum)
        {
            return false;
        }
    }
    return true;
};

bool matrix::isSquareMatrix()
{
    // cheking if matrix is square or not
    // (m26.isSquareMatrix()) ? (cout << "Yes \n") : (cout << "No \n");
    if(row_ != col_)
    {
        return false;
    }
    return true;
}

/* --------------------6) Member Functions -------------------- */

matrix matrix::transposeMatrix()
{
    matrix M(col_, row_);
    for (int i = 0; i < col_; i++)
    {
        for (int j = 0; j < row_; j++)
        {
            M.mat_[i][j] = this->mat_[j][i];
        }
    }
    return M;
}

// deconstructor
matrix::~matrix()
{
    for (int i = 0; i < row_; i++)
    {
        delete[] mat_[i];
    }
    delete[] mat_;
}
