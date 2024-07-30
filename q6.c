#include <stdio.h>

#define LIMIT 100

int main() {
    int square_of_sum = 0;
    int sum_of_squares = 0;

    for (int i = 1; i <= LIMIT; ++i) {
        square_of_sum += i;
        sum_of_squares += i * i;
    }

    square_of_sum *= square_of_sum;

    printf("%u\n", (unsigned int)square_of_sum - (unsigned int)sum_of_squares);
}
