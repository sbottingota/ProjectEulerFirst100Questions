// N.B. program takes quite a long time (around 1 minute 20 seconds on my computer)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000000

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

PrimeNode *generate_primes(int max) {
    PrimeNode *head = NULL;
    PrimeNode *tail = NULL;
    for (int i = 1; i < max; ++i) {
        if (is_prime(i)) {
            PrimeNode *new_node = malloc(sizeof(PrimeNode));
            new_node->val = i;
            new_node->next = NULL;

            if (tail != NULL) {
                tail->next = new_node;
            }

            tail = new_node;

            if (head == NULL) {
                head = new_node;
            }
        }
    }

    return head;
}

int get_consecutive_prime_sum_length(int n, PrimeNode *primes) {
    for (PrimeNode *start = primes; start != NULL; start = start->next) {
        int sum = 0;
        int length = 0;
        for (PrimeNode *prime = start; prime != NULL && sum < n; prime = prime->next) {
            sum += prime->val;
            ++length;
        }

        if (sum == n) return length;
    }

    return -1;
}

int main() {
    PrimeNode *primes = generate_primes(LIMIT);

    int max_prime = -1;
    int max_length = 0;
    for (int i = 1; i <= LIMIT; ++i) {
        if (!is_prime(i)) continue;

        int length = get_consecutive_prime_sum_length(i, primes);
        if (length > max_length) {
            max_prime = i;
            max_length = length;
        }
    }

    printf("%d\n", max_prime);

    PrimeNode *prime_next;
    for (PrimeNode *prime = primes; prime != NULL; prime = prime_next) {
        prime_next = prime->next;
        free(prime);
    }
}
