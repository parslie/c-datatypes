#ifndef HASH_MAP_PAR
#define HASH_MAP_PAR

#include <stddef.h>
#include <stdbool.h>

struct HashNode
{
    struct HashNode *next;
    void *key;
    void *value;
};
typedef struct HashNode HashNode;

struct HashBucket
{
    struct HashNode *head;
    struct HashNode *tail;
};
typedef struct HashBucket HashBucket;

struct HashMap
{
    struct HashBucket *buckets;
    size_t bucketCount;
    size_t keySize;
    size_t valueSize;
};
typedef struct HashMap HashMap;

HashMap hmap_create(size_t keySize, size_t valueSize);
void hmap_clear(HashMap *map);

void hmap_set(HashMap *map, void *key, void *value);
void *hmap_get(HashMap *map, void *key);
bool hmap_remove(HashMap *map, void *key);

#endif
