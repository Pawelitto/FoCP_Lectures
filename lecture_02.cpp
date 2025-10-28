#include <iostream>
#include <iomanip>

int main() {
    std::cout << "0.1: " << 0.1 << std::endl;
    std::cout << "0.1: " << std::setprecision(30) << 0.1 << std::endl << std::endl;

    // two zeros
    std::cout << "0.0: " << 0.0 << std::endl;
    std::cout << "-0.0: " << -0.0 << std::endl;

    std::cout << "0.0 == -0.0" << (0.0 == -0.0) << std::endl << std::endl;

    auto i = {12}; // dear compiler, figure out the best type for 'i' Here: int.

    auto pi = 1.1415;

    std::cout << typeid(i).name() << std::endl << std::endl;

    // int / int ---> int

    int a {4}, b{3};

    std::cout << a << " / " << b << " == " << a / b << std::endl; // int output
    std::cout << a << " / " << b << " == " << (double) a / b << std::endl; // double output
    std::cout << a << " / " << b << " == " << double (a) / b << std::endl; // double output

    std::cout << "4 / 3 == " << 4 / 3 << std::endl; // int output
    std::cout << "4 / 3 == " << 4.0 / 3 << std::endl << std::endl; // double output

    // modulo
    int integer {25};
    std::cout << integer % 7 << std::endl;

    if (integer % 2 == 0) {
        std::cout << integer << " is even" << std::endl;
    } else {
        std::cout << integer << " is odd" << std::endl;
    }

    if (integer % 2) {
        std::cout << integer << " is odd" << std::endl << std::endl;
    } else {
        std::cout << integer << " is even" << std::endl << std::endl;
    }

    // +=, -=, *=, /=
    integer = integer + 10;
    integer += 10;

    // bit shift
    integer = 8; // binary: 1000
    int shifted = integer << 1; // 1000

    std::cout << shifted << std::endl;

    shifted = integer >> 2; // 10
    std::cout << shifted << std::endl << std::endl;


    // Ternary operation

    double real {-23456};
    double module = real < 0 ? -real : real;

    std::cout << "|" << real << "| == " << module << std::endl << std::endl;


    // c++, ++c, c--, --c
    std::cout << a << std::endl;
    ++a; // first increment, then evaluate
    std::cout << a << std::endl;
    a++; // first evaluate, then increment
    std::cout << a << std::endl;

    std::cout << a++ << std::endl;
    std::cout << a << std::endl << std::endl;

    std::cout << ++a << std::endl;
    std::cout << a << std::endl << std::endl;


    // Lazy evaluation = 3;
    int variable = 1;
    if (variable == 1 and ++variable) { // lazy evaluation of logical expressions, and &&
        std::cout << __LINE__ << ": " << variable << std::endl;
    }
    std::cout << __LINE__ << ": " << variable << std::endl;


    std::cout << std::endl;


    variable = -1;
    if (variable != 1 || variable++) { // or
        std::cout << __LINE__ << ": " << variable << std::endl;
    }
    std::cout << __LINE__ << ": " << variable << std::endl;


    std::cout << std::endl;


    variable = 9;
    if (variable = 1) {
        std::cout << __LINE__ << ": " << "one !" << std::endl;
    } else {
        std::cout << __LINE__ << ": " << "something strange" << std::endl;
    }
    std::cout << __LINE__ << ": " << variable << std::endl;

    std::cout << std::endl;

    variable = 7;
    if (variable > 5)
        if (variable > 10)
            std::cout << __LINE__ << ": " << "more than 10" << std::endl;
        else
            std::cout << __LINE__ << ": " << "whose else it is" << std::endl;


    std::cout << std::endl;

    double value = -30;
    auto squadre_root = sqrt(value);

    std::cout << __LINE__ << ": " << squadre_root << std::endl;


    auto comparasion = squadre_root <=> 5;
    if (comparasion < 0) {
        std::cout << __LINE__ << ": " << "less" << std::endl;
    } else if (comparasion > 0) {
        std::cout << __LINE__ << ": " << "greater" << std::endl;
    } else if (comparasion == 0){
        std::cout << __LINE__ << ": " << "the same" << std::endl;
    } else {
        std::cout << __LINE__ << ": " << "comparation imposibble" << std::endl;
    }

    std::cout << std::endl;

    // LOOPS

    // WHILE

    a = 5;
    while (a < 10) {
        std::cout << a << " ";
        ++a;
    }

    std::cout << std::endl;

    a = 5;
    while (a < 10) {
        std::cout << a++ << " ";
    }

    std::cout << std::endl;

    a = 5;
    while (a > 0) {
        std::cout << a-- << " ";
    }

    std::cout << std::endl;

    a = 5;
    while (a) {
        std::cout << a-- << " ";
    }

    std::cout << std::endl;

    a = -5;
    while (a) {
        std::cout << a++ << " ";
    }

    std::cout << std::endl;

    // INFINIT LOOP
    // a = -5;
    // while (a) {
    //     std::cout << a << " ";
    // }

    // while (true)
    //     std::cout << ".";

    // while (1)
    //     std::cout << ".";


    // CTRL + D to stop input typing
    // while (std::cin >> a)
    //     std::cout << a << std::endl;


    // DO WHILE
    a = 4;
    do {
        std::cout << a++ << " ";
    } while (a < 0);

    std::cout << std::endl;

    // FOR
    for (int j = 0; j < 10; j += 2) {
        std::cout << j << " ";
    }

    // std::cout << j; j is not defined in

    std::cout << std::endl;

    return 0;
}