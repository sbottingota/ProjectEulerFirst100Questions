#include <stdio.h>
#include <math.h>

#define N_DIVISORS 500

int count_divisors(int n) {
    const int sqrt_n = sqrt(n);

    int n_divisors = 1; // including self
    if (n % 2 == 0) {
        for (int i = 1; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                if (i == sqrt_n) ++n_divisors;
                else n_divisors += 2;
            }
        }
    } else {
        for (int i = 1; i <= sqrt_n; i += 2) {
            if (n % i == 0) {
                if (i == sqrt_n) ++n_divisors;
                else n_divisors += 2;
            }
        }
    }

    return n_divisors;
}

int get_nth_triangular_number(int n) {
    return (n + 1) * (n / 2.0);
}

int main() {
    int i = 1;
    int triangular_number;
    do {
        triangular_number = get_nth_triangular_number(i);
        ++i;
    } while (count_divisors(triangular_number) <= N_DIVISORS);

    printf("%d, %d\n", i - 1, triangular_number);
}

