#include <iostream>
#include "converter.cpp"

static int curr_test = 0;
static int success_test = 0;
static int failed_test = 0;
void assert(long long number, string str1, string str2) {
    if (str1 != str2) {
        std::cerr << "Error in test " << ++curr_test << ": " << number << " expected"
                            << " to be " << str2 <<" actual :" << str1 << std::endl;
        ++failed_test;
    } else {
        std::cerr << "Succesfully passed test " << ++curr_test << std::endl;
        ++success_test;
    }
}

void test() {
    assert(0, convert_to_turkmen(0), "nol");
    assert(12, convert_to_turkmen(12), "on iki");
    assert(25, convert_to_turkmen(25), "yigrimi bash");
    assert(123, convert_to_turkmen(123), "bir yuz yigrimi uch");
    assert(999, convert_to_turkmen(999), "dokuz yuz dogsan dokuz");
    assert(1002, convert_to_turkmen(1002), "bir mun iki");
    assert(999009, convert_to_turkmen(999009), "dokuz yuz dogsan dokuz mun dokuz");
    assert(1000009, convert_to_turkmen(1000009), "bir million dokuz");
    assert(1000932, convert_to_turkmen(1000932), "bir million dokuz yuz otuz iki");
    assert(-123, convert_to_turkmen(-123), "minus bir yuz yigrimi uch");
    assert(9000000012LL, convert_to_turkmen(9000000012LL), "dokuz milliard on iki");
    std::cerr <<"Succesfully passsed test count : " << success_test << std::endl;
    std::cerr <<"Failed test count : "  << failed_test << std::endl;
}
int main() {
    test();
    long long number;
    while (1) {
        std::cout << "Enter number :";
        std::cin >> number;
        std::cout << convert_to_turkmen(number) << std::endl;
    }
    return 0;
}
