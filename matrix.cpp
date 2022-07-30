// #include<iostream>
// #include<math.h>
// #include<iomanip>
// #include <fstream>
// #include <iostream>
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
            cout << mat_[i][j] << " ";
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
    displayMatrix();
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
        displayMatrix();
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

matrix::matrix(matrix &M):row_(M.getRow()), col_(M.getRow())
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

matrix& matrix::operator=(const matrix M)
{   // operator = 
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
    return ( *this );
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
