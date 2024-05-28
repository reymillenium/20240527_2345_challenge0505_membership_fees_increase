/**
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <cmath> // for sqrt, sin, pow
#include <iomanip> // for setprecision
#include <ctime>   // For the time function
#include <sstream> // for stringstream

using namespace std;

template<typename T>
void printl(const T &item) {
    std::cout << item << std::endl;
}

string humanize_integer(int const integer_value) {
    string integer_as_string = to_string(integer_value);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = integer_as_string.length() - 3; j > 0; j -= 3) {
        integer_as_string.insert(j, ",");
    }
    return integer_as_string;
}

string humanize_double(const double double_value, const int precision = 2) {
    const int integer_value = static_cast<int>(double_value);
    const double decimals = double_value - integer_value;
    // Extracts into a string the decimal part, rounded to two significant digits
    std::stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << std::fixed << std::setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const std::string decimals_as_string = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanize_integer(integer_value) + decimals_as_string.substr(1, precision + 1);
}

string monetize_double(const double double_value, const int precision = 2) {
    return "$ " + humanize_double(double_value, precision);
}

int main() {
    const time_t now = time(nullptr); // gets current dat/time with respect to system
    const tm *local_time = localtime(&now);
    const int CURRENT_YEAR = 1900 + local_time->tm_year;

    printl("* * * * * * * * * * * * *");
    printl("*    Membership Fees    *");
    printl("* * * * * * * * * * * * *");
    printl("");
    printl("---------------------");
    printl("| YEAR |    Fees    |");
    printl("---------------------");
    for (int i = 0, year = CURRENT_YEAR; year <= CURRENT_YEAR + 6; i++, year++) {
        constexpr double INITIAL_MEMBERSHIP_CHARGE = 2500.00;
        constexpr double YEARLY_INCREASE_RATE = 1.04;

        const double membership_fees = INITIAL_MEMBERSHIP_CHARGE * pow(YEARLY_INCREASE_RATE, i);

        cout << fixed << setprecision(2) << "| " << setw(4) << year << " | " << setw(10) << monetize_double(membership_fees) << " |" << endl;
        printl("---------------------");
    }

    return 0;
}
