#include <cinttypes>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "parser.h"
#include "defaults.h"

using namespace std;

TokenParser::TokenParser(void) /*Class constructor*/
{
    this->buf = (unsigned char *)calloc(INIT_SIZE, sizeof(*buf));
    if (this->buf) {
        this->buf_size = INIT_SIZE;
    } else { /*If allocation failed, return zero-valued buffer size*/
        this->buf_size = 0;
    }
    this->int_func = base_int; /*base_int does nothing but return*/
    this->char_func = base_char; /*base_char dos nothing but return*/
}

TokenParser::~TokenParser(void) /*Class destructor*/
{
    if (this->buf) { /*Clear all allocated memory from any saved data*/
        for (uint64_t index = 0; index < this->buf_size; index++) {
            buf[index] = 0;
        }
        free(this->buf);
    }
    this->buf_size = 0;
}

void
TokenParser::change_size(uint64_t new_size) /*Complementary function; works almost like realloc*/
{
    if (!this->buf) {
        this->buf = (unsigned char *) realloc(this->buf, new_size);
        if (this->buf) {
            this->buf_size = new_size;
        } else { /*Same as in constructor: if allocation failed, return zero-valued buffer size*/
            this->buf_size = 0;
        }
    }
    else { /*Actually, we dont't use realloc in both cases because realloc(NULL, size) :=
            malloc(size), which is more unsafe, than calloc(count, size)*/
        this->buf = (unsigned char *) calloc(new_size, sizeof(*buf));
        if (this->buf) {
            this->buf_size = new_size;
        } else {
            this->buf_size = 0;
        }
    }
}

void
TokenParser::token_parse(unsigned char *string) /*Main function of class. Parses string*/
{
    if (!string) {
        return;
    }
    unsigned char *ptr = string;
    while (*ptr) {
        bool flag = 1;
        while (isspace(*ptr)) {
            ptr++;
        }
        uint64_t length = 0;
        while (*ptr && !isspace(*ptr)) {
            if (!isdigit(*ptr)) {
                flag = 0;
            }
            this->buf[length] = *ptr;
            length++;
            if (length >= this->buf_size) {
                change_size(buf_size + buf_size);
                if (!this->buf) {
                    std::cout << "MEMORY LIMIT EXCEEDED" << std::endl;
                    return;
                }
            }
            ptr++;
        }
        if (flag) {
            int_func(strtoull((const char *)(this->buf), NULL, DEC));
        } else {
            char_func(this->buf);
        }
        this->change_size(INIT_SIZE);
        if (!this->buf) {
            std::cout << "MEMORY ERROR" << std::endl;
            return;
        }
    }
}

void
TokenParser::set_func_int(func_uint64_t func) /*Sets function to procedure with uint64_t*/
{
    this->int_func = func;
}

void
TokenParser::set_func_char(func_uchar_t func) /*Sets function to procedure with unsigned char*/
{
    this->char_func = func;
}
