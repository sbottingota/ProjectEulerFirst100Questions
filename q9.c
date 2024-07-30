#include <stdio.h>
#include <stdbool.h>

#define SUM 1000

bool is_pythagorean_triplet(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    int c;

    for (int a = 1; a < SUM; ++a) {
        for (int b = 1; b < SUM; ++b) {
            c = SUM - (a + b);
            if (is_pythagorean_triplet(a, b, c)) {
                printf("%d\n", a * b * c);
                return 0;
            }
        }
    }
}
