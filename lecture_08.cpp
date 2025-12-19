#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

std::pair<int, int> get_min_max(const std::vector<int> & numbers) {
    int min = numbers.front();
    int max = numbers.back();

    for (std::size_t i = 1; i < numbers.size(); i++) {
        if (min > numbers[i]) {
            min = numbers[i];
        } else if (max < numbers[i]) {
            max = numbers[i];
        }
    }

    return std::make_pair(min, max);
}

int main () {

    std::array <int, 6> numbers;

    std::cout << numbers.size() << std::endl;

    std::cout << numbers[0] << std::endl;

    for (const int & n : numbers) {
        std::cout << n << std::endl;
    }

    std::cout << numbers.front() << std::endl;
    std::cout << numbers.back() << std::endl;


    // Structure

    struct person {
        std::string first_name; // Field
        std::string surname;
        int age;
        double height;
    };

    // type variable

    person John;

    // fields access

    John.first_name = "John";
    John.surname = "John";
    John.age = 18;
    John.height = 12.5;

    std::cout << John.first_name << std::endl;

    // std::cout << John; ERROR

    person Alice {
        "Alice",
        "Al-Zahari",
        28,
        167.99
    };

    std::cout << Alice.age << std::endl;

    std::cout << sizeof(Alice) << std::endl;
    std::cout << 2 * sizeof(std::string) + sizeof(int) + sizeof(double) << std::endl;

    // Vector of structures

    std::vector<person> team {John, Alice};
    team.push_back({
    "Pasha",
    "Biceps",
        20,
        6.7
    });

    std::cout << team.back().age << std::endl;
    std::cout << team.size() << std::endl;

    // anonymus structure

    struct {
        double x, y;
    } point_A, point_B {234.0, -57.0};

    point_A.x = 3.14;
    point_B.x = -2.71;

    // nested structures // car engine petrol etc

    std::cout << "\n========================\n\n";

    // Unions

    union element {
        int integer;
        double fpn;
    };

    element x;

    x.integer = 123456;
    std::cout << x.integer << std::endl;

    x.fpn = -4243.0534243;
    std::cout << x.integer << std::endl;

    std::cout << sizeof(element) << std::endl;
    std::cout << sizeof(int) + sizeof(double) << std::endl;


    std::cout << "\n========================\n\n";

    // Pairs

    std::pair<double, std::string> grade;
    grade.first = 123.45;
    grade.second = "Very good";

    std::cout << grade.first << std::endl;
    std::cout << grade.second << std::endl << std::endl;

    std::pair<double, bool> positive {4.5, true};

    std::cout << positive.first << std::endl;
    std::cout << positive.second << std::endl << std::endl;

    std::cout << std::get<0>(positive) << std::endl;
    std::cout << std::get<1>(positive) << std::endl << std::endl;

    std::pair<int, int> month = std::make_pair(12, 31);
    // auto month = std::make_pair(12, 31); same result

    std::cout << month.first << " " << month.second << std::endl;

    {
        std::vector<int> numbers { 45, 73, 58, 91, 23};
        std::pair<int, int> min_max = get_min_max(numbers);

        std::cout << min_max.first << ", " << min_max.second << std::endl;

    };

    {
        std::vector<int> numbers { 45, 73, 58, 91, 23};
        int Min, Max;
        std::tie(Min, Max) = get_min_max(numbers);

        std::cout << Min << ", " << Max << std::endl;

    };

    {
        std::vector<int> numbers { 45, 73, 58, 91, 23};
        auto [Min, Max] = get_min_max(numbers);

        std::cout << Min << ", " << Max << std::endl << std::endl;

    };

    // MAP

    {
        std::map<std::string, unsigned int> numbers;

        numbers["one"] = 1;
        numbers["two"] = 2;
        numbers["three"] = 3;
        numbers["four"] = 4;
        numbers["five"] = 5;
        numbers["six"] = 6;

        for (const std::pair<std::string, unsigned int> & key_value : numbers) {
            std::cout << key_value.first << " == " << key_value.second << std::endl;
        }

        std::cout << std::endl;

        for (const auto & [key, value] : numbers) {
            std::cout << key << " == " << value << std::endl;
        }

        std::cout << std::endl;

        std::map<std::string, std::string> dict_EN_IT;
        dict_EN_IT["one"] = "uno";
        dict_EN_IT["two"] = "due";
        dict_EN_IT["three"] = "tre";
        dict_EN_IT["four"] = "quattro";
        dict_EN_IT["five"] = "cinque";

        for (const auto & [english, italiano] : dict_EN_IT) {
            std::cout << english << " == " << italiano << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::unordered_map<std::string, std::string> dict_EN_IT;
        dict_EN_IT["one"] = "uno";
        dict_EN_IT["two"] = "due";
        dict_EN_IT["three"] = "tre";
        dict_EN_IT["four"] = "quattro";
        dict_EN_IT["five"] = "cinque";

        for (const auto & [english, italiano] : dict_EN_IT) {
            std::cout << english << " == " << italiano << std::endl;
        }

        std::cout << std::endl;

        std::unordered_map<int, std::string> integers;

        integers[1] = "one";
        integers[2] = "two";
        integers[3] = "three";
        integers[4] = "four";
        integers[5] = "five";
        integers[6] = "six";

        for (const auto & [key, value] : integers) {
            std::cout << key << " == " << value << std::endl;
        }

    }

    std::cout << std::endl;

    // {
    //     std::ifstream input("hamlet.txt") {
    //         std::string word;
    //         while (input >> word) {
    //             std::cout << word << std::endl;
    //         }
    //     }
    // }

    return 0;
}