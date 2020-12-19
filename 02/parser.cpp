#include <cinttypes>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "parser.h"
#include "defaults.h"

using namespace std;

TokenParser::TokenParser(void) /*Class constructor*/
{
    this->int_func = base_int; /*base_int does nothing but return*/
    this->string_func = base_string; /*base_string dos nothing but return*/
}

TokenParser::~TokenParser(void) /*Class destructor*/
{
}

void
TokenParser::token_parse(const std::string &string) /*Main function of class. Parses string*/
{
    uint64_t index = 0;
    while (index < string.length()) {
        while (index < string.length() && isspace(string[index])) {
            index++;
        }
        if (index == string.length()) {
            return;
        }
        std::string new_string = {};
        bool flag = 1;
        while (!isspace(string[index]) && index < string.length()) {
            new_string += string[index];
            if (!isdigit(string[index])) {
                flag = 0;
            } 
            index++;
        }
        if (flag) {
            int_func(std::stoll(new_string));
        } else {
            string_func(new_string);
        }
        index++;
    }
}

void
TokenParser::set_func_int(func_uint64_t func) /*Sets function to procedure with uint64_t*/
{
    this->int_func = func;
}

void
TokenParser::set_func_string(func_string_t func) /*Sets function to procedure with string*/
{
    this->string_func = func;
}
