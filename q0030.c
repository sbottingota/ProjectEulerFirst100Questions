#include <stdio.h>
#include <math.h>

#define LIMIT 1000000
#define POW 5

int main() {
    long long unsigned numbers_sum = 0;
    for (unsigned x = 2; x <= LIMIT; ++x) {
        char buf[(int) log10(x) + 2];
        sprintf(buf, "%u", x);

        long long unsigned digits_sum = 0;
        for (char *c = buf; *c != '\0'; ++c) {
            digits_sum += pow(*c - '0', POW);
        }

        if (digits_sum == x) numbers_sum += x;
    }

    printf("%llu\n", numbers_sum);
}
