#include <stdio.h>
#include <stdbool.h>


int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        int r = n % 10;
        reversed = reversed * 10 + r;
        n /= 10;
    }

    return reversed;
}

bool is_palindrome(int n) {
    return reverse(n) == n;
}

int main() {
    int max_palindrome = 0;

    for (int x = 999; x > 0; --x) {
        for (int y = 999; y > 0; --y) {
            if (x * y > max_palindrome && is_palindrome(x * y)) {
                max_palindrome = x * y;
            }
        }
    }

    printf("%d\n", max_palindrome);
}
