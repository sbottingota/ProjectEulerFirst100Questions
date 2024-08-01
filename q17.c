#include <stdio.h>

const int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000};
const int lengths[] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3,  6,  6,  8,  8,  7,  7,  9,  8,  8,  6,  6,  5,  5,  5,  7,  6,  6,  7,   8};
const int and = 3;

int index_of_number(int n) {
    for (int i = 0; i < sizeof numbers / sizeof numbers[0]; ++i) {
        if (numbers[i] == n) return i;
    }

    return -1;
}

int find_length_of_number(int n) {
    if (n < 20) {
        return lengths[index_of_number(n)];
    } else if (n < 100) {
        if (n % 10 == 0) {
            return lengths[index_of_number(n)];
        } else {
            return lengths[index_of_number(n - (n % 10))] + lengths[index_of_number(n % 10)];
        }
    } else if (n < 1000) {
        if (n % 100 == 0) {
            return lengths[index_of_number(n / 100)] + lengths[index_of_number(100)];
        } else {
            return lengths[index_of_number(n / 100)] + lengths[index_of_number(100)] + and + find_length_of_number(n % 100);
        }
    } else if (n == 1000) {
        return lengths[index_of_number(1)] + lengths[index_of_number(1000)];
    } else return -1;
}

int main() {
    int sum = 0;
    for (int n = 1; n <= 1000; ++n) {
        sum += find_length_of_number(n);
    }

    printf("%d\n", sum);
}

