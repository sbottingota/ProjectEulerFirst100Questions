#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 1000000
#define BUF_SIZE 100

bool is_palindrome(char *str) {
    char *p = str;
    char *q = str + strlen(str) - 1;

    while (p < q) {
        if (*p != *q) return false;

        ++p;
        --q;
    }

    return true;
}

int main() {
    char decimal[BUF_SIZE];
    char binary[BUF_SIZE];

    int sum = 0;

    for (int i = 1; i < LIMIT; ++i) {
        sprintf(decimal, "%d", i);
        sprintf(binary, "%b", i);

        if (is_palindrome(decimal) && is_palindrome(binary)) {
            sum += i;
            // printf("%s %s\n", decimal, binary);
        }
    }

    printf("%d\n", sum);
}

