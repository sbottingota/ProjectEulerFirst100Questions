#include <stdio.h>
#include <stdbool.h>

#define LIMIT 1000

inline bool is_pythagorean_triple(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    int best_perimeter = 0;
    int most_triples = 0;

    for (int perimeter = 3; perimeter <= LIMIT; ++perimeter) {
        int n_triples = 0;

        for (int a = 1; a < perimeter - 1; ++a) {
            for (int b = 1; b < perimeter - a; ++b) {
                int c = perimeter - (a + b);
                if (is_pythagorean_triple(a, b, c)) {
                    ++n_triples;
                }
            }
        }

        if (n_triples > most_triples) {
            best_perimeter = perimeter;
            most_triples = n_triples;
        }
    }

    printf("%d\n", best_perimeter);
}

