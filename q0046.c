#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 10000

typedef struct PrimeNode PrimeNode;
struct PrimeNode {
    int val;
    PrimeNode *next;
};

bool is_prime(int n) {
    if (n < 2) return false;    
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrt_n = sqrt(n);

    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

PrimeNode *get_primes(void) {
    PrimeNode *head = NULL;
    PrimeNode *tail = NULL;
    for (int i = 2; i < LIMIT; ++i) {
        if (is_prime(i)) {
            PrimeNode *new_node = malloc(sizeof(PrimeNode));
            new_node->val = i;
            new_node->next = NULL;

            if (tail != NULL) {
                tail->next = new_node;
            }

            tail = new_node;
            
            if (head == NULL) {
                head = tail;
            }
        }
    }

    return head;
}

bool adheres_to_conjecture(int n, PrimeNode *primes) {
    for (PrimeNode *prime = primes; prime != NULL; prime = prime->next) {
        for (int i = 1; i < LIMIT; ++i) {
            if (prime->val + 2 * i*i == n) return true;
        }
    }

    return false;
}

int main() {
    PrimeNode *primes = get_primes();

    int n = 9;

    while (adheres_to_conjecture(n, primes)) {
        do {
            n += 2;
        } while (is_prime(n));
    }

    printf("%d\n", n);

    PrimeNode *prime_next;
    for (PrimeNode *prime = primes; prime != NULL; prime = prime_next) {
        prime_next = prime->next;
        free(prime);
    }
}

