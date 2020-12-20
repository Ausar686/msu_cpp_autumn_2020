#include <iostream>
#include <cassert>
#include <sstream>
#include "matrix.h"

using namespace std;

void
size_cnt_test(void)
{
    Matrix m = Matrix(2, 3);
    assert(m.get_rows() == 2 && m.get_columns() == 3);
    std::cout << "SIZE_TEST COMPLETE" << std::endl;
}

void
value_test(void)
{
    Matrix m = Matrix(2, 3);
    m[0][0] = 404;
    assert(m[0][0] == 404);
    std::cout << "VALUE_TEST COMPLETE" << std::endl;
}

void
sum_correct_test(void)
{
    Matrix m1 = Matrix(2, 2);
    Matrix m2 = m1;
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    Matrix m3 = m1 + m2;
    assert(m3[0][0] == 6 && m3[0][1] == 8 && m3[1][0] == 10 && m3[1][1] == 12);
    std::cout << "SUMM_TEST COMPLETE" << std::endl;
}

void
mul_correct_test(void)
{
    Matrix m1 = Matrix(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    m1 *= 3;
    assert(m1[0][0] == 3 && m1[0][1] == 6 && m1[1][0] == 9 && m1[1][1] == 12);
    std::cout << "MUL_TEST COMPLETE" << std::endl;
}

void
equality_test(void)
{
    Matrix m1 = Matrix(2, 2);
    assert((m1 == m1) == 1 && (m1 != m1) == 0);
    std::cout << "EQUALITY_TEST COMPLETE" << std::endl;
}

void
wrong_size_test(void)
{
    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 2);
    try {
        Matrix m3 = m1 + m2;
        std::cout << "SIZE_SUMM_ERROR" << std::endl;
    } catch (std::out_of_range&) {
        std::cout << "DIFF_SIZE_SUMM_TEST COMPLETE" << std::endl;
    }
}

void
print_test(void)
{
    std::stringstream stream1, stream2;
    std::string str1, str2;
    Matrix m = Matrix(2, 2);
    m[0][0] = 0;
    m[0][1] = 1;
    m[1][0] = 2;
    m[1][1] = 3;
    stream1 << m;
    stream1 >> str1;
    stream2 << 0 << ' ' << 1 << ' ' << std::endl << 2 << ' ' << 3 << ' ' << std::endl;
    stream2 >> str2;
    assert(str1 == str2);
    std::cout << "PRINT_TEST COMPLETE" << std::endl;
}

int
main(int argc, char**argv)
{
    size_cnt_test();
    value_test();
    sum_correct_test();
    mul_correct_test();
    equality_test();
    wrong_size_test();
    print_test();
    std::cout << "TESTING COMPLETED" << std::endl;
    return 0;
}

