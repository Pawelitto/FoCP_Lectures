#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>

// void part(const std::string& title) {
//     static int number = 1;
//     std::stringstream sos;
//     sos << "*  part  *";
//     std::string text = sos.str();
//     std::size_t length = text.length();
//     std::cout << std::endl;
//     std::cout << std::setw(length) << std::setfill("*") << std::left << "" << std::endl;
//
//
// }

int main() {

    {
        const std::string file_name {"numbers.txt"};
        std::ofstream output_file (file_name);

        if (output_file) {
            for (int i = 10; i < 21; ++i) {
                output_file << i << std::endl;
            }
        }
    }


    {
        const std::string file_name {"numbers.txt"};
        std::ifstream input_file (file_name);

        if (input_file) {
            int number;
            while (not input_file.eof()) {
                input_file >> number;
                std::cout << number << std::endl;
            }
        }
    }

    std::cout << "=======================================" << std::endl;

    {
        const std::string file_name {"numbers.txt"};
        std::ifstream input_file (file_name);

        if (input_file) {
            int number;
            while (not input_file.eof()) {
                input_file >> number;
                if (not input_file.eof()) {
                    std::cout << number << std::endl;
                }
            }
        }
    }

    std::cout << "=======================================" << std::endl;

    {
        const std::string file_name {"numbers.txt"};
        std::ifstream input_file (file_name);

        if (input_file) {
            int number;
            while (input_file >> number) {
                std::cout << number << std::endl;
            }
        }
    }

    std::cout << "=======================================" << std::endl;

    {
        const std::string file_name {"numbers.txt"};
        std::ifstream input_file (file_name);
        int number;
        while (input_file >> number) {
            std::cout << number << std::endl;
        }
    }



    { // Part String Stream
        // #inlcude<sstream>
        {
            std::stringstream sos;
            sos << 3.24 << ", " << 65 << "a";
            std::string what_is_in_sos = sos.str();
            std::cout << what_is_in_sos << std::endl;
        }

        std::cout << "=======================================" << std::endl;

        {
            std::stringstream hamlet;
            hamlet << "To be or not to be.";

            std::string word;
            while (hamlet >> word) {
                std::cout << "{" << word << "}" << std::endl;
            }
        }

        std::cout << "=======================================" << std::endl;

        {
            std::stringstream numbers {"  4.50000000  -0.550000   17 "};

            double number;
            while (numbers >> number) {
                std::cout << "{" << number << "}" << std::endl;
            }
        }

        { // Manipulators

            const std::string PERSONS("../persons.txt");
            const std::string FORMATED("../formated.txt");

            std::ifstream file_persons (PERSONS);
            std::ofstream file_formatted (FORMATED);

            if (file_persons and file_formatted) {
                std::string first_name, last_name;
                int day,month,year;
                char character;
                double weight;
                double points;
                int rank;
                bool qualified;

                while (file_persons >> first_name >> last_name >> year >> month >> day >> character >> weight >> points >> rank >> qualified) {
                    file_formatted
                    << std::setw(20)
                    << std::left
                    << first_name
                    << std::setw(20)
                    << last_name
                    << std::setw(2)
                    << year
                    << "-"
                    << std::setw(2)
                    << std::setfill('0')
                    << month
                    << "-"
                    << std::setw(2)
                    << day
                    << " "
                    << std::setfill(' ')
                    << std::setw(10)
                    << std::setprecision(2)
                    << std::fixed
                    << weight
                    << std::setw(10)
                    << std::setprecision(2)
                    << std::fixed
                    << points
                    << std::setw(4)
                    << rank
                    << std::noshowpos
                    << std::setw(10)
                    << std::boolalpha
                    << qualified
                    << std::endl;
                }
            }
        }

        std::cout << "=======================================" << std::endl;

        // {
        //     // Stream status flags
        //
        //     std::stringstream s;
        //     std::string text {"To be or not to be."};
        //     std::cout << text << std::endl;
        //
        //     s << text;
        //     double number;
        //     s >> number;
        //
        //     std::cout << s.rdstate() << std::endl;
        //     std::cout << s.bad() << std::endl;
        //     std::cout << s.eof() << std::endl;
        //     std::cout << s.fail() << std::endl;
        //     std::cout << s.good() << std::endl;
        //
        //     s.clear();
        //
        //     //
        //
        // }

        {
            // Enum

            enum suit { spades, hearts, diamonds = 25, clubs, joker = 99};

            suit card;
            int i;

            card = spades;
            card = joker;
            card = clubs;


            std::cout << card << std::endl;
            std::cout << clubs << std::endl;
            std::cout << joker << std::endl;
            std::cout << joker - diamonds << std::endl;
            std::cout << diamonds - joker<< std::endl;

            std::cout << clubs - diamonds << std::endl;
            std::cout << clubs + diamonds << std::endl;

            card = hearts;

            switch (card) {
                case spades: std::cout << "♠" << std::endl;
                    break;
                case clubs: std::cout << "♣" << std::endl;
                    break;
                case diamonds: std::cout << "♦" << std::endl;
                    break;
                case hearts: std::cout << "♥" << std::endl;
                    break;
                case diamonds + clubs: std::cout << "♦ ♣" << std::endl;
                    break;
                default:
                    std::cout << "?????" << std::endl;
            }

            enum class face {jack, queen, king, ace};
            face _card = face::jack;

            switch (_card) {
                case face::jack : std::cout << "I'm a jack, sir." << std::endl;
                    break;
                case face::queen : std::cout << "I'm a queen, sir." << std::endl;
                    break;
                case face::king : std::cout << "I'm a king, sir." << std::endl;
                    break;
                case face::ace  : std::cout << "I'm a ace, sir." << std::endl;
                    break;
                default:
                    std::cout << "?????" << std::endl;
            }


        }
    }



    return 0;
};