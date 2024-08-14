#include <stdio.h>
#include <math.h>

#define LIMIT 1000000

long fact(int n) {
    long product = 1;
    while (n > 1) {
        product *= n;
        --n;
    }

    return product;
}

long get_digit_factorial_sum(int n) {
    char digits[(int) log10(n) + 2];
    sprintf(digits, "%d", n);

    long sum = 0;
    for (char *digit = digits; *digit != '\0'; ++digit) {
        sum += fact(*digit - '0');
    }

    return sum;
}

int main() {
    long long sum = 0;
    // 1 and 2 are excluded, as although 1! == 1 and 2! == 2, these are not sums
    for (int i = 3; i < LIMIT; ++i) {
        long digit_factorial_sum = get_digit_factorial_sum(i);
        if (digit_factorial_sum == i) sum += digit_factorial_sum;
    }

    printf("%lld\n", sum);
}
