#ifndef LINKED_LIST_PAR
#define LINKED_LIST_PAR

#include <stddef.h>

struct LinkedNode
{
    struct LinkedNode *next;
    void *data;
};
typedef struct LinkedNode LinkedNode;

struct LinkedList
{
    struct LinkedNode *head; 
    struct LinkedNode *tail;
    size_t dataSize;
    size_t length;
};
typedef struct LinkedList LinkedList;

LinkedList llist_create(size_t dataSize);
void llist_clear(LinkedList *list);

void llist_push_head(LinkedList *list, void *data);
void llist_push_tail(LinkedList *list, void *data);

#endif
