#include <stdlib.h>
#include "linked_list.h"

void linked_list_insert(Node** head, int x) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* cur = *head;
        Node* prev = NULL;
        Node* max_node = *head;
        int max_data = (*head)->data;

       while (cur != NULL) {
            if (max_data < cur->data) 
            {
                max_data = cur->data;
                max_node = cur;
            }
            prev = cur;
            cur = cur->next;
        }

        if (max_node->next != NULL) 
            new_node->next = max_node->next;

        max_node->next = new_node;
    }
}

void linked_list_delete_first_largest(Node** head) {

    Node* prev_max_node = NULL;
    Node* max_node = *head;
    Node* prev = *head;
    Node* cur = (*head)->next;

    while (cur != NULL) {
        if (cur->data > max_node->data) 
        {
            max_node = cur;
            prev_max_node = prev;
        }
        prev = cur;
        cur = cur->next;
    }

    if (prev_max_node != NULL)
        prev_max_node->next = max_node->next;
    else 
        *head = max_node->next;
}


void linked_list_half_print(Node* head) {

    int count = 0;
    Node* current = head;
    
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }

    int first_half_count = count / 2;
    int second_half_count = count - first_half_count;

    current = head;
    
    printf("First line: ");
    for (int i = 0; i < first_half_count; i++) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Second line: ");
    for (int i = 0; i < second_half_count; i++) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}