#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define TARGET 15.0
#define ARR_SIZE(spiral_width) ((spiral_width - 1) * 2)

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

double get_prime_percent(int spiral_width) {
    int current = 1;
    int step_size = 0;

    int n_prime = 0;

    for (int i = 0; i < ARR_SIZE(spiral_width); ++i) {
        if (i % 4 == 0) step_size += 2;
        current += step_size;

        // printf("\tc: %d\n", current);
        if (is_prime(current)) ++n_prime;
    }

    // printf("\tp: %lf\n", 100 * (double) n_prime / (ARR_SIZE(spiral_width) + 1));
    return 100 * n_prime / (ARR_SIZE(spiral_width) + 1); // +1 to include center
}

int main() {
    int i = 3;

    while (get_prime_percent(i) >= TARGET) i += 2;

    printf("%d\n", i);
}
