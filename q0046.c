#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 10000

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

bool adheres_to_conjecture(int n) {
    for (int i = 2; i < LIMIT; ++i) {
        for (int j = 1; j < LIMIT; ++j) {
            if (!is_prime(i)) continue;
            if (i + 2 * j*j == n) return true;
        }
    }

    return false;
}

int main() {
    int n = 9;

    while (adheres_to_conjecture(n)) {
        do {
            n += 2;
        } while (is_prime(n));
    }

    printf("%d\n", n);
}

