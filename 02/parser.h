#pragma once
#include <cinttypes>

using func_uint64_t = void(*)(uint64_t);
using func_uchar_t = void(*)(unsigned char *);

class TokenParser
{
private:
    unsigned char *buf;
    uint64_t buf_size;
    func_uint64_t int_func;
    func_uchar_t char_func;
    func_uint64_t base_int_func;
    func_uchar_t base_char_func;
public:
    TokenParser(void);
    ~TokenParser(void);
    void change_size(uint64_t);
    void token_parse(unsigned char *);
    void set_func_int(func_uint64_t);
    void set_func_char(func_uchar_t);
};

enum
{
    INIT_SIZE = 100,
    DEC = 10
};
