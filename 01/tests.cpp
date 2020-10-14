#include <cassert>
#include <cstddef>
#include <iostream>
#include "alloc.h"

using namespace std;

void first_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size = 1;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr = allocator->alloc(size);
    assert (base && base == ptr);
    std::cout << "FIRST TEST PASSED" << std::endl;
    delete allocator;
}

void two_alloc_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size1 = 2;
    size_t size2 = 3;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr1 = allocator->alloc(size1);
    char *ptr2 = allocator->alloc(size2);
    assert (base && base == ptr1 && ptr2 == base + 2);
    std::cout << "DOUBLE ALLOC TEST PASSED" << std::endl;
    delete allocator;
}

void too_big_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size = 11;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr = allocator->alloc(size);
    assert (ptr == nullptr && base);
    std::cout << "OVERFLOW TEST PASSED" << std::endl;
    delete allocator;
}

void too_big_test_again(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size1 = 2;
    size_t size2 = 9;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr1 = allocator->alloc(size1);
    char *ptr2 = allocator->alloc(size2);
    assert(base && base == ptr1 && !ptr2);
    std::cout << "SECOND TEST PASSED" << std::endl;
    delete allocator;
}

void precise_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size1 = 4;
    size_t size2 = 6;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr1 = allocator->alloc(size1);
    char *ptr2 = allocator->alloc(size2);
    assert (base && base == ptr1 && ptr2 == base + 4);
    std::cout << "FULL SIZE USAGE TEST PASSED" << std::endl;
    delete allocator;
}

void precise_test_again(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size1 = 4;
    size_t size2 = 6;
    size_t size3 = 1;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr1 = allocator->alloc(size1);
    char *ptr2 = allocator->alloc(size2);
    char *ptr3 = allocator->alloc(size3);
    assert (base && base == ptr1 && ptr2 == base + 4 && !ptr3);
    std::cout << "FULL SIZE & OVERFLOW TEST PASSED" << std::endl;
    delete allocator;
}

void reset_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size = 10;
    size_t size1 = 4;
    size_t size2 = 3;
    allocator->make_allocator(max_size);
    char *base = allocator->get_base();
    char *ptr1 = allocator->alloc(size1);
    char *ptr2 = allocator->alloc(size2);
    allocator->reset();
    assert (base && base == ptr1 && ptr2 == base + 4 && !(allocator->get_cur() - base));
    std::cout << "RESET TEST PASSED" << std::endl;
    delete allocator;
}

void double_init_test(void)
{   
    Allocator *allocator = new Allocator(nullptr, nullptr, 0);
    size_t max_size1 = 10;
    size_t max_size2 = 15;
    allocator->make_allocator(max_size1);
    char *base1 = allocator->get_base();
    allocator->make_allocator(max_size2);
    char *base2 = allocator->get_base();
    assert(base1 && base2 && base1 == base2);
    std::cout << "DOUBLE INIT TEST PASSED" << std::endl;
    delete allocator;
}
