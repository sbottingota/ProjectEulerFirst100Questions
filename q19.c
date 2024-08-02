#include <stdio.h>
#include <stdbool.h>

const int month_lengths_normal[]    = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int month_lengths_leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int weekday = 365 % 7; // 1st Jan 1900 was a monday (0), and was also not a leap year, hence 365 % 7

    int n_sundays = 0;

    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 0; month <= 11; ++month) {
            for (int day = 0; day < (is_leap_year(year) ? month_lengths_leap_year[month] : month_lengths_normal[month]); ++day) {
                if (weekday == 6 && day == 1) ++n_sundays;

                weekday = (weekday + 1) % 7;
            }
        }
    }

    printf("%d\n", n_sundays);
}
