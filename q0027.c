#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000

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

int check_formula(int a, int b) {
    int score = 0;

    int n = 0;
    while (is_prime(n*n + a*n + b)) {
        ++score;
        ++n;
    }

    return score;
}

int main() {
    int best_a = 0, best_b = 0;
    int highest_score = 0;

    for (int a = -LIMIT; a < LIMIT; ++a) {
        for (int b = -LIMIT; b < LIMIT; ++b) {
            int score = check_formula(a, b);
            if (score > highest_score) {
                best_a = a;
                best_b = b;
                highest_score = score;
            }
        }
    }

    printf("%d\n", best_a * best_b);
}
    
