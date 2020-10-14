#include <cstddef>
#include "alloc.h"

Allocator::Allocator(char *base, char *cur, size_t size)
{
    this->base_ptr = base;
    this->cur_ptr = cur;
    this->alloc_size = size;
}

Allocator::~Allocator(void)
{
    if (this->base_ptr) {
        delete[] base_ptr;
    }
}

void Allocator::make_allocator(size_t max_size)
{
    if (!(this->base_ptr) && max_size) { 
    // protection from allocating 0-sized memory part
        this->base_ptr = new char[max_size];
        this->cur_ptr = this->base_ptr;
        if (this->base_ptr) {
        // protection from changing alloc_size if max_size is too big and base_ptr == nullptr
            this->alloc_size = max_size;
        }
    }
}

char * Allocator::alloc(size_t size)
{
    if (!this->base_ptr || this->cur_ptr - this->base_ptr + size > this->alloc_size) {
    // requires make_allocator first to return non-null value
        return nullptr;
    } else {
        this->cur_ptr += size;
        return this->cur_ptr - size;
    }
}

void Allocator::reset(void)
{
    this->cur_ptr = this->base_ptr;
    for (size_t index = 0; index < this->alloc_size; index++) {
    // memory clear after reset; if memory is not allocated, nothing happens
        this->base_ptr[index] = 0;
    }
}

char * Allocator::get_base(void)
{
    return this->base_ptr;
}

char * Allocator::get_cur(void)
{
    return this->cur_ptr;
}

size_t Allocator::get_size(void)
{
    return this->alloc_size;
}
