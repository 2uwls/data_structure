#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void linked_list_insert(Node* head, int x);
void linked_list_delete_first_largest(Node* head);
void linked_list_print(Node* head);
