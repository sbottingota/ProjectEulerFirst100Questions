#include <stdio.h>
#include <math.h>

#define LIMIT 1000
#define N_DIGITS 10

unsigned long truncated_pow(unsigned long x, unsigned long n) {
    unsigned long product = 1;

    for (unsigned long i = 0; i < n; ++i) {
        product *= x;
        product %= (unsigned long) pow(10, N_DIGITS);
    }

    return product;
}

int main() {
    unsigned long sum = 0;

    for (unsigned long i = 1; i <= LIMIT; ++i) {
        sum += truncated_pow(i, i);
        sum %= (unsigned long) pow(10, N_DIGITS);

        // printf("%lu\n", sum);
    }

    printf("%lu\n", sum);
}

