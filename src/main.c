#include <stdio.h>

#include "linked_list.h"
#include "fill_random_num.h"

int main() {
    int nums[50];
    fill_random_num(nums, 50);
    Node* head = NULL;

    for (int i=0; i<50; i++)
        linked_list_insert(&head, nums[i]);


    for (int i=0;i<4;i++)
    {
        printf("step %d\n",i+1);
        linked_list_delete_first_largest(&head);
        linked_list_half_print(head);
        printf("\n");
    }
   

    return 0;
}
