#include <iostream>
#include <cinttypes>
#include <cstdio>
#include <string>
#include <cassert>
#include "parser.h"

using namespace std;

static uint64_t ans_int = 0;
static std::string ans_string{};
static uint64_t ans_str_int = 0;


/*ARGUMENT FUNCTIONS FOR UINT64_T & UNSIGNED CHAR * */
void
dig_sum(uint64_t num) /*Prints decimal sum of digits in given number*/
{
    uint64_t tmp = num;
    while (tmp) {
        ans_int += tmp % MOD;
        tmp /= MOD;
    }
}

void
square(uint64_t num) /*Prints a ^ 2*/
{
    ans_int += num * num;
}

void
append_string(std::string string) /*Prints string*/
{
    ans_string += string + " ";
}

void
length(std::string string) /*Prints string & string.length()*/
{
    ans_str_int += string.length();
}

/*TESTS*/

/*DISCLAIMER: Unfortunately, the developer is too poor to perform a test with a string, such that:
string.length() > ULLONG_MAX, so it's an undefined behaviour guaranteed for this cases, if any other 
programmers will encounter such kind of situation.*/

void
init_test(void) /*Basic init test with base int & string functions, which simply does nothing*/
{
    ans_int = 0;
    ans_string = {};
    TokenParser parser;
    parser.token_parse(std::string{"Hello, darkness, my old friend..."});
    assert(ans_int == 0 && ans_string.length() == 0);
    std::cout << "INIT TEST COMPLETED" << std::endl;
}

void
string_test(void) /*First simple test on a single string & simple custom strlen-print function*/
{
    ans_int = 0;
    ans_str_int = 0;
    ans_string = {};
    TokenParser parser;
    parser.set_func_int(square);
    parser.set_func_string(append_string);
    parser.token_parse(std::string{"I've come to talk with you again..."});
    assert(ans_int == 0 && ans_string == "I've come to talk with you again... ");
    std::cout << "STRING TEST COMPLETED" << std::endl;
}

void
dig_sum_test(void) /*Checks first unsigned-integer-valued string*/
{
    ans_int = 0;
    ans_str_int = 0;
    ans_string = {};
    TokenParser parser;
    parser.set_func_int(dig_sum);
    parser.set_func_string(length);
    parser.token_parse(std::string{"57"});
    assert(ans_int == 12 && ans_string.length() == 0 && ans_str_int == 0);
    std::cout << "DIGIT SUMM TEST COMPLETED" << std::endl;
}

void
complex_test(void) /*Checks whether we treat negative ints as uint64_t or not*/
{
    ans_int = 0;
    ans_str_int = 0;
    ans_string = {};
    TokenParser parser;
    parser.set_func_int(square);
    parser.set_func_string(append_string);
    parser.token_parse(std::string{"201 GGWP -121"});
    assert(ans_int == 40401 && ans_string == "GGWP -121 ");
    std::cout << "COMPLEX TEST COMPLETED" << std::endl;
}

void
combine_test(void) /*Checks all types of isspace true-values*/
{
    ans_int = 0;
    ans_str_int = 0;
    ans_string = {};
    TokenParser parser;
    parser.set_func_int(dig_sum);
    parser.set_func_string(length);
    parser.token_parse(std::string{"322w33w33\v0\nFEE1\rDEAD\t101\f404"});
    assert(ans_int == 10 && ans_str_int == 17);
    std::cout << "COMBINE TEST COMPLETED" << std::endl;
}

/*TESTS EXECUTION*/
int
main(int argc, char **argv)
{
    init_test();
    string_test();
    dig_sum_test();
    complex_test();
    combine_test();
    std::cout << "TESTING COMPLETED!" << std::endl;
    return 0;
}
