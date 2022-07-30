// #include<iostream>
// #include<math.h>
// #include<iomanip>
// #include <fstream>
// #include <iostream>
// #include <cstring>
#include<bits/stdc++.h>
#include <iostream>
#include"matrix.hpp"
using namespace std;

int main()
{
    // matrix m;

    // cout << "enter filename :" << endl;
    // char filename[50];
    // cin >> filename;
    // matrix m1(filename);

    // matrix m2(49, 49);

    // cout << "enter filename :" << endl;
    // char filename[50];
    // cin >> filename;
    // matrix m3(3,3,filename);

    // cout << "Enter new filename for output :" << endl;
    // char filename2[50];
    // cin >> filename2;
    // // m3.printMatrix(filename2);
    // matrix m4(4,4);
    // m4.printMatrix(filename2);

    // matrix m5(3);

    // matrix m6(2);
    // m6.cmdInput();
    // m6.displayMatrix();
    // m6.printMatrix();

    // cout << "enter filename :" << endl;
    // char filename[50];
    // cin >> filename;
    // matrix m7(3, filename);

    // matrix m8;
    // m8.displayMatrix();
    // cout << "----------" << endl;
    // matrix m9(m8);
    // m9.displayMatrix();

    matrix m10;
    m10.displayMatrix();
    cout << "----------" << endl;
    matrix m11 = m10;
    m11.displayMatrix();

    return 0;
}

