#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define LIMIT 10001

bool is_prime(int n) {
    if (n % 2 == 0) return false;

    int sqrt_n = sqrt(n);

    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int count = 1; // including 2
    int n = 1;
    while (count < LIMIT) {
        do {
            n += 2; 
        } while (!is_prime(n));

        ++count;
    }

    printf("%d\n", n);
}

