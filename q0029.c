#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <gmp.h>

#define START 2
#define LIMIT 100

typedef struct Node {
    mpz_ptr val;
    struct Node *next;
} Node;

void power(int x, unsigned int y, mpz_ptr target) {
    if (y == 0) {
        mpz_set_si(target, 1);
        return;
    }

    power(x, y / 2, target);

    if ((y % 2) == 0) {
        mpz_mul(target, target, target);
    } else {
        mpz_mul(target, target, target);
        mpz_mul_si(target, target, x);
    }
}

bool contains(Node *list_head, mpz_t x) {
    for (Node *node = list_head; node != NULL; node = node->next) {
        if (mpz_cmp(node->val, x) == 0) return true;
    }
    return false;
}

int length(Node *list_head) {
    int i = 0;
    while (list_head != NULL) {
        list_head = list_head->next;
        ++i;
    }

    return i;
}

int main() {
    Node *distinct_nums = NULL;
    
    for (int a = START; a <= LIMIT; ++a) {
        for (int b = START; b <= LIMIT; ++b) {
            mpz_ptr result = alloca(sizeof(mpz_t));
            mpz_init(result);

            power(a, b, result);

            if (distinct_nums == NULL) {
                distinct_nums = malloc(sizeof(Node));
                distinct_nums->val = result;
                distinct_nums->next = NULL;
                continue;
            }

            if (contains(distinct_nums, result)) {
                mpz_clear(result);
                continue;
            }

            Node *new_head = malloc(sizeof(Node));
            new_head->val = result;
            new_head->next = distinct_nums;
            distinct_nums = new_head;
        }
    }

    printf("%d\n", length(distinct_nums));

    Node *next_node;
    for (Node *node = distinct_nums; node != NULL; node = next_node) {
        next_node = node->next;
    
        mpz_clear(node->val);
        free(node);
    }
}
