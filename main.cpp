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
    // m1.displayMatrix();

    // matrix m2(49, 49);

    // cout << "enter filename :" << endl;
    // char filename[50];
    // cin >> filename;
    // matrix m3(3,3,filename);
    // m3.displayMatrix();

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

    // matrix m10;
    // m10.displayMatrix();
    // cout << "----------" << endl;
    // matrix m11 = m10;
    // m11.displayMatrix();

    // matrix m12, m13;
    // m12.displayMatrix();
    // cout << "----------" << endl;
    // m13.displayMatrix();
    // cout << "-----ANS-----" << endl;
    // matrix m14 = m12 + m13;
    // m14.displayMatrix();

    // matrix m15, m16;
    // m15.displayMatrix();
    // cout << "----------" << endl;
    // m16.displayMatrix();
    // cout << "-----ANS-----" << endl;
    // matrix m17 = m15 - m16;
    // m17.displayMatrix();

    // matrix m18;
    // m18.displayMatrix();
    // cout << "----------" << endl;
    // cout << "enter filename :" << endl;
    // char filename[50];
    // cin >> filename;
    // matrix m19(filename);
    // m19.displayMatrix();
    // cout << "-----ANS-----" << endl;
    // matrix m20 = m18 * m19;
    // m20.displayMatrix();

    // matrix m21;
    // cout << m21;

    // matrix m22;
    // cin >> m22;
    // m22.displayMatrix();

    // matrix m23;
    // m23.displayMatrix();
    // cout << "----------" << endl;
    // m23.scalarMultiplication(0.5);
    // m23.displayMatrix();

    // matrix m24;
    // m24.displayMatrix();
    // cout << "----------" << endl;
    // m24.scalarDivision(2);
    // //cout << m24;
    // m24.displayMatrix();

    // matrix m25;
    // m25.displayMatrix();
    // cout << m25.isDiagonalDominant();
    // (m25.isDiagonalDominant()) ? (cout << "Yes \n") : (cout << "No \n");
    
    // matrix m26;
    // m26.displayMatrix();
    // (m26.isSquareMatrix()) ? (cout << "Yes \n") : (cout << "No \n");

    matrix m26;
    m26.transposeMatrix();
    m26.displayMatrix();
    cout << "--------------" << endl;
    cout << m26.transposeMatrix();

    
    return 0;
}

