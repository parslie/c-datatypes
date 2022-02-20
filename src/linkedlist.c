#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

LinkedList llist_create(size_t dataSize)
{
    LinkedList list = { NULL, NULL, dataSize, 0 };
    return list;
}

void llist_clear(LinkedList *list)
{
    LinkedNode *curr = list->head;
    while (curr != NULL)
    {
        LinkedNode *next = curr->next;
        free(curr->data);
        free(curr);
        curr = next;
    }
    list->length = 0;
}

void llist_push_head(LinkedList *list, void *data)
{
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = malloc(list->dataSize);
    memcpy(node->data, data, list->dataSize);
    
    if (list->tail == NULL)
        list->tail = node;
    else if (list->head != NULL)
        node->next = list->head;

    list->head = node;
    list->length++;
}

void llist_push_tail(LinkedList *list, void *data)
{
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = malloc(list->dataSize);
    memcpy(node->data, data, list->dataSize);
    
    if (list->head == NULL)
        list->head = node;
    else if (list->tail != NULL)
        list->tail->next = node;

    list->tail = node;
    list->length++;
}
