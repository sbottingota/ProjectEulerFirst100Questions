#include <stdio.h>
#include <math.h>


long int find_largest_prime_factor(long int n) {
    long int largest_factor = 0;
    long int d = 2;

    while (n > 1) {
        while (n % d == 0) {
            if (largest_factor < d) {
                largest_factor = d;
            }
            n /= d;
        }
        ++d;
    }

    return largest_factor;
    
}

// find the largest prime factor of n
int main() {
    const long int n = 600851475143;

    long int i = find_largest_prime_factor(n);
    printf("%ld\n", i);
}

    
