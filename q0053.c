#include <stdio.h>
#include <gmp.h>

#define LIMIT 100
#define BOUND 1000000

int main() {
    mpz_t n_fact, r_fact, n_minus_r_fact;
    mpz_init(n_fact);
    mpz_init(r_fact);
    mpz_init(n_minus_r_fact);

    int count = 0;

    for (int n = 1; n <= LIMIT; ++n) {
        for (int r = 1; r <= n; ++r) {
            mpz_fac_ui(n_fact, n);
            mpz_fac_ui(r_fact, r);
            mpz_fac_ui(n_minus_r_fact, n - r);

            mpz_mul(r_fact, r_fact, n_minus_r_fact);
            mpz_cdiv_q(n_fact, n_fact, r_fact);

            if (mpz_cmp_ui(n_fact, BOUND) > 0) {
                ++count;
            }
        }
    }

    printf("%d\n", count);

    mpz_clear(n_fact);
    mpz_clear(r_fact);
    mpz_clear(n_minus_r_fact);
}

