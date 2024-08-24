#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "q0022.txt"
#define BUF_SIZE 50000

struct NameNode {
    char name[16];
    struct NameNode *next;
};

typedef struct NameNode NameNode;

void sort(NameNode *names_head) {
    for (NameNode *node = names_head; node != NULL; node = node->next) {
        NameNode *min = node;
        for (NameNode *other = node->next; other != NULL; other = other->next) {
            if (strcmp(min->name, other->name) > 0) {
                min = other;
            }
        }

        char temp[16];
        strcpy(temp, min->name);
        strcpy(min->name, node->name);
        strcpy(node->name, temp);
    }
}

void replace_all(char *str, char old, char new) {
    char *c;
    while ((c = strchr(str, old)) != NULL) {
        *c = new;
    }
}

void remove_all(char *str, char c) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';
}        

NameNode *parse_string(char *str) {
    char *token = strtok(str, " ");
    NameNode *head = NULL;
    NameNode *prev = NULL;
    NameNode *current;

    while (token != NULL) {
        current = malloc(sizeof(NameNode));
        if (head == NULL) {
            head = current;
        }

        strcpy(current->name, token);

        if (prev != NULL) {
            prev->next = current;
        }

        prev = current;

        token = strtok(NULL, " ");
    }
    
    current->next = NULL;
    return head;
}

int get_score(char *name) {
    int sum = 0;
    for (char *c = name; *c != '\0'; ++c) {
        sum += *c - 'A' + 1;
    }
    return sum;
}

int main() {
    FILE *fp = fopen(FILE_PATH, "r");

    char buf[50000] = {0};
    fgets(buf, 50000, fp);
    replace_all(buf, ',', ' ');
    remove_all(buf, '"');

    fclose(fp);

    NameNode *names = parse_string(buf);
    sort(names);

    int i = 0;
    NameNode *node = names;
    NameNode *next;

    int sum = 0;

    while (node != NULL) {
        sum += (i + 1) * get_score(node->name);

        next = node->next;
        free(node);
        node = next;

        ++i;
    }

    printf("%d\n", sum);
}
