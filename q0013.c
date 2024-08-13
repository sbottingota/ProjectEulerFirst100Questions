#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILE_PATH "./q13.txt"
#define READ_LENGTH 52 // 50 chars, plus "\n\0"
#define N_DIGITS 10
#define PRECISION 12

long parse_int_approx(char *large_int) {
    char truncated_large_int[PRECISION + 1] = {0};
    memcpy(truncated_large_int, large_int, PRECISION);
    long x = strtol(truncated_large_int, NULL, 10);

    return x;
}

int main() {
    FILE *fp;
    fp = fopen(FILE_PATH, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error in opening file '%s'\n", FILE_PATH);
        return 1;
    }

    char buffer[READ_LENGTH] = {0};
    long sum = 0;

    while (fgets(buffer, READ_LENGTH, fp)) {
        sum += parse_int_approx(buffer);
    }

    fclose(fp);

    while (((int)log10(sum)) >= N_DIGITS) sum /= 10;

    printf("%ld\n", sum);
}

    
    
