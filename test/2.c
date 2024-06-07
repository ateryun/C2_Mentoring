#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num1;
    int num2;
    struct Node *next;
    struct Node *prev;
} Node;

int main(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    for (int i = 0; i < 10; i++) {
        temp->next = (Node *)malloc(sizeof(Node));
        temp->next->prev = temp;
        temp->num1 = rand() % 10;
        temp->num2 = rand() % 10;
        temp = temp->next;
        temp->next = NULL;
    }

    temp = head;
    while (temp->next != NULL) {
        printf("%d %d\n", temp->num1, temp->num2);
        temp = temp->next;
    }
    printf("\n");

    while (temp != NULL) {
        printf("%d %d\n", temp->num1, temp->num2);
        temp = temp->prev;
    }

    temp = head;
    Node *nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

