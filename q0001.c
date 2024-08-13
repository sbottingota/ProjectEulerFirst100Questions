#include <stdio.h>


// find the sum of all numbers that are multiples of 3 or 5 under 1000
int main() {
    int sum = 0;

    for (int i = 1; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    
    printf("%d\n", sum);
}

