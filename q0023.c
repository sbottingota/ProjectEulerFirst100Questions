// N.B. program takes a long time (~2min on my pc)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 28123

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// get the sum of all the factors of n (except for n)
int get_factors_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) sum += i;
    }

    return sum;
}

int generate_next_abundant_number(int last_number) {
    int n = last_number + 1;
    while (get_factors_sum(n) <= n) {
        ++n;
    }

    return n;
}

// calculated_head must be the largest calculated value
bool is_sum_of_two_abundant_nums(int n, Node **calculated_head) {
    while ((*calculated_head)->data < n) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = generate_next_abundant_number((*calculated_head)->data);
        new_node->next = *calculated_head;
        *calculated_head = new_node;
    }

    for (Node *node1 = *calculated_head; node1 != NULL; node1 = node1->next) {
        for (Node *node2 = *calculated_head; node2 != NULL; node2 = node2->next) {
            if (node1->data + node2->data == n) return true;
        }
    }

    return false;
}

int main() {
    Node *calculated_head = malloc(sizeof(Node));
    calculated_head->data = generate_next_abundant_number(0);
    calculated_head->next = NULL;

    int sum = 0;

    for (int i = 1; i <= LIMIT; ++i) {
        if (!is_sum_of_two_abundant_nums(i, &calculated_head)) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    Node *node_next;
    for (Node *node = calculated_head; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }
}

