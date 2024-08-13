#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 2e6


bool is_prime(int n) {
    if (n % 2 == 0) return false;

    int sqrt_n = sqrt(n);

    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    long sum = 2;
    for (long i = 3; i < LIMIT; i += 2) {
        if (is_prime(i)) {
            sum += i;
        }
    }

    printf("%ld\n", sum);
}
