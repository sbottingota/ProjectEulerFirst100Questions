#include <stdio.h>
#include <gmp.h>

#define N_DIGITS 1000

int main() {
    mpz_t a, b, c;
    mpz_init(a);
    mpz_init(b);
    mpz_init(c);

    mpz_set_ui(a, 0);
    mpz_set_ui(b, 1);

    int i = 2;

    do {
        mpz_add(c, a, b);
        mpz_set(a, b);
        mpz_set(b, c);
        
        ++i;
    } while (mpz_sizeinbase(c, 10) < N_DIGITS);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);

    printf("%d\n", i);
}

