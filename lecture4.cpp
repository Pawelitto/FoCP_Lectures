//
// Created by Paweł Pietras on 27/10/2025.
//

#include <iostream>
#include <random>
#include <chrono>
#include <math.h>

double f_sum (double x, double y) {
    double result;
    result = x + y;
    return result;
}

auto f_sum_2 (double x, double y) -> double {
    return x + y;
}

auto f_sum_3 (double x, double y) {
    return x + y;
}

auto f_sum_4 (auto x, auto y) {
    return x + y;
}

void print_stars(int s) {
    std::cout << "[";
    while (s > 0) {
        std::cout << "*";
        --s;
    }
    std::cout << "]" << std::endl;

}

void increment(int & a) { // no copying!!!
    ++a;
}

void print_stars_rec(int s) {
    if (s > 0) { // if there are any stars to be printed
        std::cout << "*";
        print_stars_rec(s - 1);
    }
}

long int power(const int n, const int e) {
    if (e > 0) {
        return n * power(n, e - 1);
    } else {
        return 1;
    }
}

long int power_soph(const int n, const int e) {
    if (e > 0) {
        long int half = power_soph(n, e / 2);

        if (e % 2) { // odd
            return half * half * n;
        } else {
            return half * half;
        }
    } else {
        return 1;
    }
}

long int power_more_soph(const int n, const int e) {
    if (e > 0) {
        long int half = power_soph(n, e / 2);

        return e % 2 ? half * half * n : half * half;
    } else {
        return 1;
    }
}

double pi_monte_carlo (const long int shots) {
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_real_distribution<double> distro(-1, 1);

    long int circle = 0;
    for (long int i = 0; i < shots; ++i) {
        double x = distro(engine);
        double y = distro(engine);

        if (x * x + y * y < 1) {
            circle++;
        }
    }

    return 4.0 * circle / shots;
}

inline
double absolute (const double x) {
    return x < 0 ? -x : x;
}

int main() {
    {
        int i = 1;
        {
            int a;
            i = 2;
            int i = -1;
            {
                i = 3;
                int i = 4;
            }
            i = 5;
        }
        std::cout << i << std::endl << std::endl;
    }
    // std::cout << i << std::endl; ERROR int "i" was not declared in this scope


    // single functions
    std::cout << sin(1.71) << std::endl << std::endl;


    double a {3.14}, b{2.71};
    double sum = f_sum (a, b);
    std::cout << sum << std::endl;
    std::cout << f_sum_2(a, b) << std::endl;
    std::cout << f_sum_3(a, b) << std::endl;
    std::cout << f_sum_4(a, b) << std::endl << std::endl;

    // parameter passing
    // ... by value (copy)

    int number_of_stars { 3 };
    std::cout << number_of_stars << std::endl;
    print_stars(number_of_stars);
    std::cout << number_of_stars << std::endl << std::endl;

    // ... by reference
    increment(number_of_stars);
    std::cout << number_of_stars << std::endl << std::endl;

    // recursion
    print_stars_rec(number_of_stars);
    std::cout << std::endl << std::endl;

    // ... powers
    int number { 2 };
    int exponent { 10 };
    long int result;

    for (int exponent = 0; exponent < 11; ++exponent) {
        std::cout << number << " to " << exponent << " == " << power(number, exponent) << " | " << power_soph(number, exponent) << " | " << power_more_soph(number, exponent) << std::endl;
    }

    std::cout << std::endl;

    // example: monte carlo
    double pi_est = pi_monte_carlo(1'000'000);
    std::cout << pi_est << std::endl;

    for (long int i = 1000; i < 100'000'000; i *= 10) {
        auto pi_est = pi_monte_carlo(i);
        std::cout << i << " i " << pi_est << ", " << pi_est - M_PI << std::endl;
    }

    // inline
    std::cout << absolute(-3223.432) << std::endl;
    std::cout << (-3223.432 < 0 ? -3223.432 : 3223.432) << std::endl;
}

