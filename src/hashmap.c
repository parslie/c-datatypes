#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 10

HashMap hmap_create(size_t keySize, size_t valueSize)
{
    HashBucket *buckets = calloc(DEFAULT_CAPACITY, sizeof(HashBucket));
    HashMap hashMap = { buckets, DEFAULT_CAPACITY, keySize, valueSize };
    return hashMap;
}

void hmap_clear(HashMap *map)
{

}

void hmap_set(HashMap *map, void *key, void *value)
{
    size_t hash = 0; // TODO: create proper hash function
    HashBucket *bucket = map->buckets + sizeof(HashBucket) * hash;

    HashNode *curr = bucket->head;
    while (curr != NULL && memcmp(key, curr->key, map->keySize) != 0)
        curr = curr->next;

    if (curr == NULL)
    {
        HashNode *newNode = malloc(sizeof(HashNode));
        newNode->key = malloc(map->keySize);
        newNode->value = malloc(map->valueSize);
        memcpy(newNode->key, key, map->keySize);
        memcpy(newNode->value, value, map->valueSize);
        newNode->next = NULL;

        if (bucket->tail == NULL)
            bucket->head = newNode;
        else
            bucket->tail->next = newNode;
        bucket->tail = newNode;
    }
    else
        memcpy(curr->value, value, map->valueSize);
}

void *hmap_get(HashMap *map, void *key)
{
    size_t hash = 0; // TODO: create proper hash function
    HashBucket bucket = map->buckets[hash];

    HashNode *curr = bucket.head;
    while (curr != NULL)
    {
        if (memcmp(key, curr->key, map->keySize) == 0)
            return curr->value;
        curr = curr->next;
    }

    return NULL;
}

void hmap_remove(HashMap *map, void *key)
{
    size_t hash = 0; // TODO: create proper hash function
}