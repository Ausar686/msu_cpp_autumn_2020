#pragma once
#include <cinttypes>
#include <functional>

using func_uint64_t = std::function <void(uint64_t)>;
using func_string_t = std::function <void(std::string)>;

class TokenParser
{
private:
    func_uint64_t int_func;
    func_string_t string_func;
public:
    TokenParser(void);
    ~TokenParser(void);
    void token_parse(std::string);
    void set_func_int(func_uint64_t);
    void set_func_string(func_string_t);
    void set_defaults(void);
};

enum
{
    MOD = 10
};
