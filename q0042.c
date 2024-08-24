#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define FILE_PATH "./q0042.txt"
#define BUF_SIZE 20000

bool is_triangle_number(int n) {
    int i = 1;
    while (n > 0) {
        n -= i;
        ++i;
    }

    return n == 0;
}

bool is_triangle_word(char *word) {
    int sum = 0;

    for (char *c = word; *c != '\0'; ++c) {
        if (isupper(*c)) {
            sum += *c - 'A' + 1;
        }
    }

    return is_triangle_number(sum);
}

int main() {
    FILE *fp;
    fp = fopen(FILE_PATH, "r");

    if (fp == NULL) {
        fprintf(stderr, "Unable to open file\n");
        return 1;
    }

    char buf[BUF_SIZE];
    fgets(buf, BUF_SIZE, fp);

    int count = 0;

    char *token = strtok(buf, ",");

    while (token != NULL) {
        // printf("%s\n", token);
        if (is_triangle_word(token)) ++count;

        token = strtok(NULL, ",");
    }

    printf("%d\n", count);
}

