#ifndef HASH_MAP_PAR
#define HASH_MAP_PAR

#include <stddef.h>

struct HashNode
{
    struct HashNode *next;
    void *key;
    void *value;
};
typedef struct HashNode HashNode;

struct HashMap
{
    struct HashNode **buckets;
    size_t capacity;
    size_t keySize;
    size_t valueSize;
};
typedef struct HashMap HashMap;

HashMap hmap_create(size_t keySize, size_t valueSize);
void hmap_clear(void);

void hmap_set(void *key, void *value);
void *hmap_get(void *key);
void hmap_remove(void *key);

#endif
