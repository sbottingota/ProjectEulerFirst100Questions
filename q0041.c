#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 100000000

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrt_n = sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool is_pandigital(int n) {
    char digits[(int) log10(n) + 2];
    sprintf(digits, "%d", n);

    int n_digits = strlen(digits);
    for (int i = 1; i <= n_digits; ++i) {
        if (strchr(digits, i + '0') == NULL) return false;
    }

    return true;
}

int main() {
    int max = 0;

    for (int i = 2; i <= LIMIT; ++i) {
        if (is_pandigital(i) && is_prime(i)) {
            max = i;
        }
    }

    printf("%d\n", max);
}

