#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define LIMIT 10000
#define ITERATIONS 50

uint64_t reversed(uint64_t n) {
    char digits[(uint64_t) log10(n) + 2];
    sprintf(digits, "%lu", n);

    char *p = digits;
    char *q = digits + strlen(digits) - 1;
    char temp;
    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;

        ++p;
        --q;
    }

    return strtoul(digits, NULL, 10);
}

bool is_palindrome(uint64_t n) {
    return n == reversed(n);
}

bool is_lychrel_number(uint64_t n) {
    int i = 0;

    do {
        n += reversed(n);
        ++i;
    } while (i < ITERATIONS && !is_palindrome(n));

    return !is_palindrome(n);
}

int main() {
    int count = 0;

    for (int n = 1; n < LIMIT; ++n) {
        if (is_lychrel_number(n)) {
            // printf("%d\n", n);
            ++count;
        }
    }

    printf("%d\n", count);
}

