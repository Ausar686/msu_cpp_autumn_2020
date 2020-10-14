#include <iostream>
#include "tests.h"
#include "alloc.h"

using namespace std;

int main(int argc, char **argv)
{
    first_test();
    two_alloc_test();
    too_big_test();
    too_big_test_again();
    precise_test();
    precise_test_again();
    reset_test();
    double_init_test();
    std::cout << "TESTING COMPLETED. SUCCESS!" << std::endl;
    return 0;
}
