#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 10000000
#define BUF_SIZE 9

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

bool is_ltr_trunc_prime(char *num) {
    for (char *s = num; *s != '\0'; ++s) {
        if (!is_prime(atoi(s))) return false;
    }

    return true;
}

// N.B. overwrites string
bool is_rtl_trunc_prime(char *num) {
    for (int i = strlen(num) - 1; *num != '\0'; --i) {
        if (!is_prime(atoi(num))) return false;
        num[i] = '\0';
    }

    return true;
}

int main() {
    char num[BUF_SIZE];

    int sum = 0;
    for (int i = 10; i <= LIMIT; ++i) {
        sprintf(num, "%d", i);

        if (!is_ltr_trunc_prime(num)) continue;
        if (!is_rtl_trunc_prime(num)) continue;

        // printf("%d\n", i);
        sum += i;
    }

    printf("%d\n", sum);
}

