#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MULTIPLIER_LIMIT 6

bool have_same_digits(int x, int y) {
    if (floor(log10(x)) != floor(log10(y))) return false;

    char x_digits[(int) log10(x) + 2];
    char y_digits[(int) log10(y) + 2];

    sprintf(x_digits, "%d", x);
    sprintf(y_digits, "%d", y);

    for (char *digit = x_digits; *digit != '\0'; ++digit) {
        char *p = strchr(y_digits, *digit);
        if (p == NULL) return false;

        *p = '-'; // filler char
    }

    return true;
}

bool are_multiples_permuted(int n) {
    for (int m = 2; m <= MULTIPLIER_LIMIT; ++m) {
        if (!have_same_digits(n, n * m)) return false;
    }

    return true;
}

int main() {
    int n = 1;
    while (!are_multiples_permuted(n)) ++n;

    printf("%d\n", n);
}

