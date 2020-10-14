#pragma once
#include <cstddef>

class Allocator
{
    private:
        char *base_ptr;
        char *cur_ptr;
        size_t alloc_size;
    public:
        Allocator(char *, char *, size_t);
        ~Allocator(void);
        void make_allocator(size_t);
        char *alloc(size_t);
        void reset(void);
        char *get_base(void);
        char *get_cur(void);
        size_t get_size(void);
};
