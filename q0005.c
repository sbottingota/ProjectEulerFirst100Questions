#include <stdio.h>
#include <stdbool.h>

// returns if n is divisible by all numbers up to m (inclusive)
bool is_divisible(int n, int m) {
    for (int i = 1; i <= m; ++i) {
        if (n % i != 0) return false;
    }

    return true;
}
    

int main() {
    int n = 1;
    
    while (!is_divisible(n, 20)) {
        ++n;
    }
    printf("%d\n", n);        
}
