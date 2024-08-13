#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

#define LIMIT 1000

int main() {
    mpz_t product;
    mpz_init(product);
    mpz_set_si(product, 1);

    for (int i = 0; i < LIMIT; ++i) {
        mpz_mul_si(product, product, 2);
    }

    char *str = mpz_get_str(NULL, 10, product);
    mpz_clear(product);

    int sum = 0;

    for (char *c = str; *c != '\0'; ++c) {
        sum += *c - '0';
    }

    free(str);

    printf("%d\n", sum);
}
