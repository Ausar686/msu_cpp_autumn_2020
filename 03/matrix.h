#pragma once
#include <iostream>

class Row
{
private:
    size_t columns;
    int *row_ptr;
public:
    //Row(size_t);
    Row(int *, size_t);
    ~Row(void);
    size_t get_columns(void) const;
    int & operator[](size_t) const;
    friend std::ostream & operator<<(std::ostream &, Row const &);
};

class Matrix
{
private:
    size_t rows;
    size_t columns;
    int *matrix_ptr;
public:
    Matrix(size_t, size_t);
    Matrix(int **, size_t, size_t);
    Matrix(Matrix const &);
    ~Matrix(void);
    size_t get_rows(void) const;
    size_t get_columns(void) const;
    int *get_ptr(void);
    Row & operator[](size_t) const;
    Matrix & operator*=(int);
    Matrix & operator=(Matrix &);
    friend std::ostream & operator<<(std::ostream &, Matrix const &);
    friend Matrix & operator+(Matrix const &, Matrix const &);
    friend bool operator==(Matrix const &, Matrix const &);
    friend bool operator!=(Matrix const &, Matrix const &);
};
