#include <stdlib.h>
#include "linked_list.h"

void linked_list_insert(Node* head, int x)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* cur;
        cur = head;
        int max_data = head->data;
        Node* max_node = head;
        while (cur != NULL) {
            if (max_data < cur->data)
            {
                max_data = cur->data;
                max_node = cur;
            }

            cur = head->next;
        }

        Node* temp = max_node->next;
        
        max_node->next = new_node;
        new_node->next = temp;
    }
}