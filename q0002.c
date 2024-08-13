#include <stdio.h>

#define LIMIT 4000000 // 4 million


// find the sum of all even fibonacci numbers less than LIMIT
int main() {
    int a = 0;
    int b = 1;
    int c = 1;

    int sum = 0;

    while (c < LIMIT) {
        if (c % 2 == 0) {
            sum += c;
        }

        printf("%d ", c);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n%d\n", sum);
}

