#include <stdio.h>
#include "linkedlist.h"
#include "hashmap.h"

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

void test_hash_map(void)
{
    HashMap map = hmap_create(sizeof(char), sizeof(int));

    char key1 = 's';
    char key2 = 'c';
    int setVal1 = 69;
    int setVal2 = 420;
    hmap_set(&map, &key1, &setVal1);
    hmap_set(&map, &key2, &setVal2);

    int getVal1 = *(int *)hmap_get(&map, &key1);
    int getVal2 = *(int *)hmap_get(&map, &key2);

    printf("Value of '%c': %d\n", key1, getVal1);
    printf("Value of '%c': %d\n\n", key2, getVal2);

    char key3 = 'a';
    int *getVal3 = (int *)hmap_get(&map, &key3);
    printf("Pointer to node '%c' value: %p\n", key3, getVal3);

    int setVal3 = 42069;
    hmap_set(&map, &key3, &setVal3);
    getVal3 = (int *)hmap_get(&map, &key3);
    printf("Pointer to node '%c' value: %p\n", key3, getVal3);
    printf("Value of '%c': %d\n", key3, *getVal3);

    printf("\nSetting value of '%c' to value of '%c'...\n", key2, key1);
    hmap_set(&map, &key2, &setVal1);
    getVal2 = *(int *)hmap_get(&map, &key2);
    printf("Value of '%c': %d\n", key2, getVal2);

    printf("\nLooping through buckets (head -> tail)...\n");
    for (size_t i = 0; i < map.bucketCount; i++)
    {
        HashBucket bucket = map.buckets[i];
        printf("Bucket '%d': (%p -> %p)\n", i, bucket.head, bucket.tail);
    }

    printf("\nClearing map...");
    hmap_clear(&map);

    printf("\nLooping through buckets (head -> tail)...\n");
    for (size_t i = 0; i < map.bucketCount; i++)
    {
        HashBucket bucket = map.buckets[i];
        printf("Bucket '%d': (%p -> %p)\n", i, bucket.head, bucket.tail);
    }

    printf("\nDeleting map...\n");
    hmap_free(&map);
}

void test_hash_map_removal(void)
{
    HashMap map = hmap_create(sizeof(char), sizeof(int));
    int value = 3;

    printf("Populating map with 64 key-values...\n");
    for (char i = 0; i < 64; i++)
        hmap_set(&map, &i, &value);

    printf("\nLooping through buckets (head -> tail)...\n");
    for (size_t i = 0; i < map.bucketCount; i++)
    {
        HashBucket bucket = map.buckets[i];
        printf("Bucket '%d': (%p -> %p)\n", i, bucket.head, bucket.tail);
    }

    printf("\nRemoving every key...\n");
    for (char i = 0; i < 64; i += 2)
        hmap_remove(&map, &i);

    printf("\nLooping through buckets (head -> tail)...\n");
    for (size_t i = 0; i < map.bucketCount; i++)
    {
        HashBucket bucket = map.buckets[i];
        printf("Bucket '%d': (%p -> %p)\n", i, bucket.head, bucket.tail);
    }

    printf("\nDeleting map...\n");
    hmap_free(&map);
}

int main(int argc, char *argv[])
{
    char *divider = "------------------------------------";

    printf("%s\n Linked List:\n%s\n", divider, divider);
    test_linked_list();
    printf("%s\n Hash Map:\n%s\n", divider, divider);
    test_hash_map();
    printf("%s\n Hash Map (removal):\n%s\n", divider, divider);
    test_hash_map_removal();
    return 0;
}