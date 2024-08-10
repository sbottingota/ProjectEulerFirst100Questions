// N.B. program requires gmp to be compiled manually with gmp linked.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>

#define LIMIT 100

int main() {
    mpz_t product;
    mpz_init(product);
    mpz_set_ui(product, 1);

    for (int i = 2; i <= LIMIT; ++i) {
        mpz_mul_si(product, product, i);
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
    
