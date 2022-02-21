#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUCKET_COUNT 10

HashMap hmap_create(size_t keySize, size_t valueSize)
{
    HashBucket *buckets = calloc(DEFAULT_BUCKET_COUNT, sizeof(HashBucket));
    HashMap hashMap = { buckets, DEFAULT_BUCKET_COUNT, keySize, valueSize };
    return hashMap;
}

void hmap_clear(HashMap *map)
{

}

size_t generate_hash(HashMap *map, void *key)
{
    size_t tmp = 0;
    memcpy(&tmp, key, map->keySize);
    return tmp % map->bucketCount;
}

void hmap_set(HashMap *map, void *key, void *value)
{
    size_t hash = generate_hash(map, key);
    HashBucket *bucket = map->buckets + hash;

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
    size_t hash = generate_hash(map, key);
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

bool hmap_remove(HashMap *map, void *key)
{
    size_t hash = generate_hash(map, key);
    HashBucket *bucket = map->buckets + hash;

    HashNode *prev = NULL;
    HashNode *curr = bucket->head;
    while (curr != NULL)
    {
        if (memcmp(key, curr->key, map->keySize) == 0)
        {
            if (prev != NULL)
                prev->next = curr->next;
            else
                bucket->head = curr->next;

            if (curr->next == NULL)
                bucket->tail = prev;

            free(curr->key);
            free(curr->value);
            free(curr);

            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    return false;
}