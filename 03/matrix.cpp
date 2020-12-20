#include "matrix.h"
#include <iostream>

Row::Row(int *array, size_t columns)
{
    this->row_ptr = array;
    this->columns = columns;
}

Row::~Row(void)
{
}

size_t
Row::get_columns(void) const
{
    return this->columns;
}

int &
Row::operator[](size_t column) const
{
    if (column >= this->columns) {
        throw std::out_of_range("");
    }
    return this->row_ptr[column];
}

std::ostream &
operator<<(std::ostream &stream, Row const &row)
{
    for (size_t column = 0; column < row.get_columns(); column++) {
        stream << row[column] << ' ';
    }
    stream << std::endl;
    return stream;
}







Matrix::Matrix(size_t rows, size_t columns)
{
    this->matrix_ptr = new int[rows * columns];
    if (this->matrix_ptr) {
        this->rows = rows;
        this->columns = columns;
        for (size_t row = 0; row < rows; row++) {
            for (size_t column = 0; column < columns; column++) {
                this->matrix_ptr[row * columns + column] = 0;
            }
        }
    } else {
        throw std::out_of_range("");//not enough memory
    }

}

Matrix::Matrix(int **array, size_t rows, size_t columns)
{
    this->matrix_ptr = new int[rows * columns];
    if (this->matrix_ptr) {
        this->rows = rows;
        this->columns = columns;
    } else {
        throw std::out_of_range("");//not enough memory
    }
    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            this->matrix_ptr[row * columns + column] = array[row][column];
        }
    }
}

Matrix::Matrix(Matrix const &m)
{
    this->matrix_ptr = new int[m.get_rows() * m.get_columns()];
    if (this->matrix_ptr) {
        this->rows = m.get_rows();
        this->columns = m.get_columns();
    } else {
        throw std::out_of_range("");//not enough memory
    }
    for (size_t row = 0; row < this->rows; row++) {
        for (size_t column = 0; column < this->columns; column++) {
            this->matrix_ptr[row * columns + column] = m[row][column];
        }
    }
}

Matrix::~Matrix(void)
{
    if (this->matrix_ptr) {
        delete[] this->matrix_ptr;
    }
}


size_t
Matrix::get_rows(void) const
{
    return this->rows;
}

size_t
Matrix::get_columns(void) const
{
    return this->columns;
}

int *
Matrix::get_ptr(void)
{
    return this->matrix_ptr;
}

Row &
Matrix::operator[](size_t row) const
{
    if (row > this->rows) {
        throw std::out_of_range("");
    }
    Row *tmp = new Row(this->matrix_ptr + row * this->columns, this->columns);
    return *tmp;
}

Matrix &
Matrix::operator*=(int mul)
{
    if(!this->matrix_ptr) {
        throw std::out_of_range("");
    }
    for (size_t row = 0; row < this->rows; row++) {
        for (size_t column = 0; column < this->columns; column++) {
            this->matrix_ptr[row * this->columns + column] *= mul;
        }
    }
    return *this;
}

Matrix &
Matrix::operator=(Matrix &m)
{
    if (this->matrix_ptr == m.get_ptr()) {
        return *this;
    }
    if (this->matrix_ptr) {
        delete[] this->matrix_ptr;
    }
    this->matrix_ptr = new int[m.get_rows() * m.get_columns()];
    if (!this->matrix_ptr) {
        throw std::out_of_range("");
    }
    rows = m.get_rows();
    columns = m.get_columns();
    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            this->matrix_ptr[row * columns + column] = m[row][column];
        }
    }
    return *this;
}

std::ostream &
operator<<(std::ostream &stream, Matrix const &m)
{
    for (size_t row = 0; row < m.get_rows(); row++) {
        stream << m[row];
    }
    return stream;
}

Matrix &
operator+(Matrix const &m1, Matrix const &m2)
{
    if (m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns()) {
        throw std::out_of_range("");
    }
    Matrix *tmp = new Matrix(m1);
    for (size_t row = 0; row < m1.get_rows(); row++) {
        for (size_t column = 0; column < m1.get_columns(); column++) {
            tmp->get_ptr()[row * m1.get_columns() + column] += m2[row][column];
        }
    }
    return *tmp;
}

bool
operator==(Matrix const &m1, Matrix const &m2)
{
    if (m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns()) {
        return 0;
    }
    for (size_t row = 0; row < m1.get_rows(); row++) {
        for (size_t column = 0; column < m1.get_columns(); column++) {
            if (m1[row][column] != m2[row][column]) {
                return 0;
            }
        }
    }
    return 1;
}

bool
operator!=(Matrix const &m1, Matrix const &m2)
{
    return !(m1 == m2);
}
