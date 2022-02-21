#include "hashmap.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY 10

HashMap hmap_create(size_t keySize, size_t valueSize)
{
    HashNode **buckets = calloc(DEFAULT_CAPACITY, sizeof(HashNode *));
    HashMap hashMap = { buckets, DEFAULT_CAPACITY, keySize, valueSize };
    return hashMap;
}

void hmap_clear(void)
{

}

void hmap_set(void *key, void *value)
{
}

void *hmap_get(void *key)
{

}

void hmap_remove(void *key)
{

}