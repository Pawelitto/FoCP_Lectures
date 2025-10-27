#include <iostream>
#include <iomanip>

int main() {

    std::cout << "Hello World!" << std::endl;

    int f_123;

    std::cout << sizeof(f_123) << std::endl;

    int initialized = 970;

    std::cout << initialized << std::endl;

    int one_more_variable { -32323 };
    std::cout << one_more_variable << std::endl;

    // std::cin >> f_123;

    std::cout << f_123 << std::endl;
    std::cout << sizeof(f_123) << std::endl;

    std::string str = "Hello World!";

    float zmienno_przecinkowa = 121.22;

    std::cout << zmienno_przecinkowa << std::endl;

    std::cout << sizeof(zmienno_przecinkowa) << std::endl;

    bool condition = false;
    std::cout << condition << std::endl;

    condition = "dsdsssd";
    std::cout << condition << std::endl;

    if (condition) {
        std::cout << "działa if" << std::endl;
    }

    bool right = true;
    bool direction = right;

    if (direction == right) {
        std::cout << "go right" << std::endl;
    } else {
        std::cout << "go left" << std::endl;
    }

    return 0;
}
