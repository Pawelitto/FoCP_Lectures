#include <iostream>
#include <random>
#include <chrono>
#include <vector>

/** if only possible, the compiler tries to evaluate the function during compilation
 *
 * @return  the function always returns 12.
 * @date 2025-11-03
 * @author "Paweł Pietras"
 */
constexpr
int twelve() {
    return 12;
}


/** if only possible, the compiler tries to evaluate the value of the function during compilation.
 *  If is not possible to evaluate, it is not a function whose value is elaborated during the execution for the
 */
constexpr
long int factorial_iter(const int n) {
    long int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}


/** if only possible, the compiler tries to evaluate the value of the function during compilation.
 *  If is not possible to evaluate, the program won't compile
 */
consteval
long int factorial_rec (const int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial_rec(n - 1);
    }

}


/** @return consecutive numbers
 */
int consecutive_number() {
    static int result {0};
    return result++;
}


/** The function print somebody's name and surname
 *  @return  array
 *  @param surname
 *  @param first_name
 *  @param second_name
 *
 */
void print_person(const std::string surname, const std::string first_name, const std::string second_name = "") {
    std::cout << surname << " " << first_name << " " << second_name << std::endl;
}


/** The function print an array.
 *  @return  array
 *  @param lenght lenght of the array
 *
 */
void print(double array [], const int lang) {
    std::cout << "[";
    for (int i = 0; i < lang; i++) {
        std::cout << array[i];
    }
    std::cout << "]" << std::endl;
}

void fill (double array [], const int length) {
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());

    std::normal_distribution<double> distro (170, 15);

    for (int i = 0; i < length; i++) {
        array[i] = distro (engine);
    }
}


void print (const std::vector<int> & vec) {
    std::cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;
}


void fill (std::vector<int> & vec) {
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> distro (100, 999);

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = distro (engine);
    }
}

int main () {
    const int CONST {23};

    int variable = 654;

    const int CONST_VARIABLE = variable;

    constexpr int constexpr_known_to_compilation_time = 45;
    // constexpr_known_to_compilation_time = 65;
    // constexpr int name = variable; // variable can't be used to initialise the constexpr

    int array[twelve()];

    std::cout << factorial_rec(5) << std::endl;
    std::cout << factorial_rec(1) << std::endl;
    std::cout << factorial_rec(0) << std::endl;

    int long_array_1 [factorial_iter(5)];
    int number {4};
    // int long_array_2 [factorial_iter(number)];

    std::cout << factorial_iter(number) << std::endl;

    // std::cout << factorial_rec(number) << std::endl; // the value of parameter not known in compilation

    int long_array_3 [factorial_rec(0)];



    // static variable in function
    for (int i = 0; i < 5; i++) {
        std::cout << consecutive_number() << std::endl;
    }


    // default parameters
    print_person("Kubica", "Robert", "John");
    print_person("Doe", "Adam", "");
    print_person("Doe", "Adam");


    // passing arrays
    const int N {6};
    double values [N];

    print(values, N);
    fill(values, N);
    print(values, N);

    // std::vector
    // ----type----  ---variable----
    std::vector<int> numbers;

    std::cout << numbers.size() << std::endl;
    numbers.push_back(12);
    std::cout << numbers.size() << std::endl;

    std::cout << numbers[0] << std::endl;

    for (int i = 0; i < 13; i++) {
        numbers.push_back(i*i);
    }

    std::cout << numbers.size() << std::endl;

    print(numbers);
    numbers.pop_back();
    print(numbers);
    fill(numbers);
    print(numbers);


    std::cout << numbers[5] << std::endl;
    std::cout << numbers[500] << std::endl;
    std::cout << numbers.at(5) << std::endl;
    // std::cout << numbers.at(500) << std::endl;


    std::vector<int> points{1,5,7,2,73,9,1,6,3,6,464,5,3};
    print(points);

    // std::string

    std::string hamlet {"To be or not be. that is the question"};
    std::cout << hamlet << std::endl;
    std::cout << hamlet.size() << std::endl;
    std::cout << hamlet.length() << std::endl;

    hamlet.push_back('.');

    std::cout << hamlet.size() << std::endl;
    std::cout << hamlet << std::endl;
    std::cout << hamlet[26] << std::endl;



    std::vector<std::string> soliloquy;
    soliloquy.push_back(hamlet);

    soliloquy.push_back("Whether tis nobel in the pain to suffer");

    for (int i = 0; i < soliloquy.size(); i++) {
        std::cout << soliloquy[i] << std::endl;
    }


    return  0;
}