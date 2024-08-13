#include <stdio.h>

#define LIMIT 1e6

long get_collatz_sequence_length(long start_number) {
    long n = start_number;
    long length = 1; // including self

    while (n > 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        ++length;
    }

    return length;
}

int main() {
    long longest_sequence_start = -1;
    long longest_sequence_length = 0;

    long length;

    for (long start_number = 0; start_number < LIMIT; ++start_number) {
        length = get_collatz_sequence_length(start_number);
        if (length > longest_sequence_length) {
            longest_sequence_start = start_number;
            longest_sequence_length = length;
        }
    }

    printf("%ld\n", longest_sequence_start);
}
