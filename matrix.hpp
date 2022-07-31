class matrix
{
private:
    /* data members*/
    int row_, col_;
    double **mat_;

public:
    matrix();
    //to get data members
    inline int getRow(void) const; 
    inline int getCol(void) const;
    // // to set data members
    void setter(const int row, const int col);
    // to create matirx from obj's row and col
    void matrixCreate();
    //  printing matrix in a file method
    void printMatrix();
    // diplay matrix to terminal
    void displayMatrix();
    // getting cmdline input from user
    void cmdInput();

/* --------------------overloading methods--------------------*/
    
    // output file name as argument
    void printMatrix(char filename[50]);
    // filename as argument
    matrix(char filename[50]);
    // matrix form row and col no
    matrix(int row, int col);
    // matrix given row and col and filename
    matrix(int row, int col, char filename[50]);
    // square matrix
    matrix(int row);
    // square matrix and input from file
    matrix(int row, char filename[50]);
    // copy matrix
    matrix(matrix &M);

    /* --------------------operator overloading-------------------- */
    // operator =
    matrix& operator=(const matrix M);
    // operator +
    matrix operator+(matrix &M) const;
    // operator - 
    matrix operator-(matrix &M) const;
    // operator *
    matrix operator*(matrix &M) const;
    // operator << 
    friend std::ostream &operator<<( std::ostream& , const matrix &M);
    // operator >>
    friend std::istream &operator>>( std::istream& , matrix &M);

    /* --------------------Scalar Muti and Division-------------------- */
    void scalarMultiplication(double num);
    void scalarDivision(double num);

    /* --------------------6) Member Functions -------------------- */
    bool isDiagonalDominant();

    /* --------------------System of Linear Equations-------------------- */



    // deconstructor
    ~matrix();
};
