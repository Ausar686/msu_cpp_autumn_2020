#include <iostream>
#include <cinttypes>
#include <cstdio>
#include "parser.h"

using namespace std;

enum
{
    MOD = 10,
    BUF_SIZE = 10000
};


/*ARGUMENT FUNCTIONS FOR UINT64_T & UNSIGNED CHAR * */
void
dig_sum(uint64_t num) /*Prints decimal sum of digits in given number*/
{
    uint64_t tmp = num;
    uint64_t res = 0;
    while (tmp) {
        res += tmp % MOD;
        tmp /= MOD;
    }
    std::cout << "DIGIT SUM OF " << num << " IS: " << res << std::endl;
}

void
square(uint64_t num) /*Prints a ^ 2*/
{
    std::cout << "SQUARE OF " << num << " IS: " << num * num << std::endl;
}

void
char_print(unsigned char *string) /*Prints string*/
{
    std::cout << "IT'S A STRING! <<" << string << ">>" <<  std::endl;
}

void
length(unsigned char *string) /*Prints string & strlen(string)*/
{
    unsigned char *tmp = string;
    uint64_t res = 0;
    while (*tmp) {
        res++;
        tmp++;
    }
    std::cout << "THE LENGTH OF <<" << string << ">> IS: " << res << std::endl;
}

/*TESTS*/

/*DISCLAIMER: Unfortunately, the developer is too poor to perform a test with a string, such that:
strlen(string) > ULLONG_MAX, so it's an undefined behaviour guaranteed for this cases, if any other 
programmers will encounter such kind of situation.*/

void
init_test(void) /*Basic init test with base int & char functions, which simply do nothing*/
{
    TokenParser *parser = new TokenParser();
    parser->token_parse((unsigned char *) "Hello, darkness, my old friend...");
    delete parser;
}

void
empty_test(void) /*Checks whether the class can hadle with NULL-valued argument*/
{
    TokenParser *parser = new TokenParser();
    parser->set_func_int(dig_sum);
    parser->set_func_char(char_print);
    parser->token_parse(NULL);
    delete parser;
}

void
letter_test(void) /*First simple test on a single letter & simple custom strlen-print function*/
{
    TokenParser *parser = new TokenParser();
    parser->set_func_int(square);
    parser->set_func_char(length);
    parser->token_parse((unsigned char *) "a");
    delete parser;
}

void
dig_sum_test(void) /*Checks first unsigned-integer-valued string*/
{
    TokenParser *parser = new TokenParser();
    parser->set_func_int(dig_sum);
    parser->set_func_char(char_print);
    parser->token_parse((unsigned char *) "57");
    delete parser;
}

void
complex_test(void) /*Checks whether we treat negative ints as uint64_t or not*/
{
    TokenParser *parser = new TokenParser();
    parser->set_func_int(square);
    parser->set_func_char(char_print);
    parser->token_parse((unsigned char *) "201 GGWP -121");
    delete parser;
}

void
combine_test(void) /*Checks all types of isspace true-values*/
{
    TokenParser *parser = new TokenParser();
    parser->set_func_int(dig_sum);
    parser->set_func_char(length);
    parser->token_parse((unsigned char *) "322w33w33\v0\nFEE1\rDEAD\t101\f404");
    delete parser;
}

/*TESTS EXECUTION*/
int
main(int argc, char **argv)
{
    empty_test();
    letter_test();
    dig_sum_test();
    complex_test();
    combine_test();
    return 0;
}
