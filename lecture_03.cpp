#include <iostream>

int main() {
    int pips_on_dice {4};

    switch (pips_on_dice) { // int, char, enum
        case 6 : std::cout << "******" << std::endl; break;
        case 5 : std::cout << "*****" << std::endl; break;
        case 4 : std::cout << "****" << std::endl; break;
        case 3 : std::cout << "***" << std::endl; break;
        case 2 : std::cout << "**" << std::endl; break;
        case 1 : std::cout << "*" << std::endl; break;

        default : std::cout << "???" << std::endl; break;
    }

    std::cout << "==================== Example with no 'break' ====================" << std::endl;

    switch (pips_on_dice) { // int, char, enum
        case 6 : std::cout << "*";
        case 5 : std::cout << "*";
        case 4 : std::cout << "*";
        case 3 : std::cout << "*";
        case 2 : std::cout << "*";
        case 1 : std::cout << "*" << std::endl; break;

        default : std::cout << "???" << std::endl; break;
    }

    std::cout << std::endl;
    // Arrays

    const int SIZE { 5 };
    int array [SIZE]; // The length of the array must be known in compilation time!

    std::cout << std::endl;
    // Item access

    std::cout << array[1] << std::endl;

    std::cout << std::endl;
    // Print an array

    std::cout << "[ ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << array << std::endl; // Location in computer memory

    // 0[array] array[0]

    std::cout << array[2] << std::endl;
    std::cout << 2[array] << std::endl;

    // Array initialization

    int raw[15];
    for (int i = 0; i < 15; ++i) {
        std::cout << raw[i] << " ";
    }

    std::cout << std::endl;

    // Initialization
    int initialised[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 8; ++i) {
        std::cout << initialised[i] << " ";
    }

    std::cout << std::endl;

    int partialy_initialised[15] = {1, 2, 3, 4, 5, 6, 7, 8}; // The rest of array is 0
    for (int i = 0; i < 15; ++i) {
        std::cout << partialy_initialised[i] << " ";
    }

    std::cout << std::endl;

    int zeros[15] = { }; // Default int value is 0 so all array is filled up with 0
    for (int i = 0; i < 15; ++i) {
        std::cout << zeros[i] << " ";
    }

    std::cout << std::endl;

    // Too short array - ILLEGAL CODE
    // int too_short[5] = {1, 2, 3, 4, 5, 6, 7, 8};
    // for (int i = 0; i < 5; ++i) {
    //     std::cout << too_short[i] << " ";
    // }

    //

    char characters [] = {'H', 'a', 'm', 'l', 'e', 't'};
    for (int i = 0; i < 6; ++i) {
        std::cout << characters[i] << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long double) << std::endl;

    std::cout << sizeof(zeros) << std::endl;
    std::cout << sizeof(zeros) / sizeof(int) << std::endl;

    std::cout << sizeof(characters) << std::endl;
    std::cout << sizeof(characters) / sizeof(char) << std::endl;

    std::cout << std::endl;

    //

    const int N {6};
    double numbers [N];

    for (int i = 0; i < N; ++i) {
        numbers[i] = sqrt(100 * i + 5);
    }

    std::cout << "[ ";
    for (int i = 0; i < N; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout <<  " ]" << std::endl;

    std::cout << "Average" << std::endl;

    double sum (0.5);
    // for (int i = 0; i < N; ++i) {
    //     sum += numbers[i];
    // }

    std::cout << sum / N << std::endl;

    std::cout << std::endl;

    // Reverse the array

    int left = 0;
    int right = N - 1;

    while (left <= right) {
        auto tmp = numbers[left];
        numbers[left] = numbers[right];
        numbers[right] = tmp;
        left++;
        right--;
    }

    std::cout << "[ ";
    for (int i = 0; i < N; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout <<  " ]" << std::endl;

    std::cout << std::endl;

    // Dimencional Arrays

    const int ROWS = 9;
    const int COLUMNS = 9;
    int array2d[ROWS][COLUMNS];

    // Fill an array (FIRST WAY) - un comment this and comment second way to try it!

    // int first_row = 0;
    // int first_column = 0;
    //
    // int past_the_last_row = ROWS;
    // int past_the_last_column = COLUMNS;
    //
    // int value = 0;
    //
    // while (first_row < past_the_last_row and first_column < past_the_last_column) {
    //     for (int col = first_column; col < past_the_last_column; ++col) {
    //         array2d[first_row][col] = value;
    //     }
    //
    //     for (int row = first_row; row < past_the_last_row; ++row) {
    //         array2d[row][past_the_last_column - 1] = value;
    //     }
    //
    //     for (int col = past_the_last_column - 1; col >= first_column; --col) {
    //         array2d[past_the_last_row - 1][col] = value;
    //     }
    //
    //     for (int row = past_the_last_row; row >= first_row; --row) {
    //         array2d[row][first_column] = value;
    //     }
    //
    //     first_row++;
    //     first_column++;
    //
    //     past_the_last_row--;
    //     past_the_last_column--;
    //
    //     value++;
    // }

    // Fill an array (SECOND WAY)

    int counter = 1; // bustrefoorm
    std::cout << "=======================" << std::endl;
    for (int row = 0; row < ROWS; ++row) {
        if (row % 2) {
            for (int col = 0; col < COLUMNS; ++col) {
                array2d[row][col] = counter++;
            }
        } else {
            for (int col = COLUMNS - 1; col >= 0; --col) {
                array2d[row][col] = counter++;
            }
        }
    }

    std::cout << "=======================" << std::endl;

    // Print an array

    std::cout << "=======================" << std::endl;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS; ++col) {
            std::cout << array2d[row][col] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "=======================" << std::endl;

    std::cout << std::endl;

    //
    int arra2d [][2] = {
        {1, 0},
        {2, 3},
        {6, 8},
        {9, 5}
    };

    // std::cout << cahraters[100] << std::endl;
    // std::cout << cahraters[10000000] << std::endl;

    return 0;
}