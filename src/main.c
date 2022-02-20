#include <stdio.h>
#include "linkedlist.h"

void test_linked_list(void)
{
    LinkedList list = llist_create(sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        llist_push_head(&list, &i);
        printf("Added %d to list head\n", i);
    }

    int tmp = 10;
    llist_push_tail(&list, &tmp);
    printf("Added %d to list tail\n\n", tmp);

    LinkedNode *curr = list.head;
    size_t index = 0;
    while (curr != NULL)
    {
        printf("Value at %d: %d \n", index, *(int *)(curr->data));
        curr = curr->next;
        index++;
    }

    printf("\nPre-clear list length: %d\n", list.length);
    llist_clear(&list);
    printf("Post-clear list length: %d\n", list.length);
}

int main(int argc, char *argv[])
{
    char *divider = "------------------------------------";

    printf("%s\n Linked List:\n%s\n", divider, divider);
    test_linked_list();
    return 0;
}