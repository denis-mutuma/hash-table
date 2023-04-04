#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// type definition for a linked list node
typedef struct
{
    uint32_t key;
    uint32_t value;
    struct Node *next;
} Node;

// type definition for a hash table
typedef struct
{
    size_t capacity;
    Node **data;
} HashTable;

// Function creates a new linked list node on the heap and initializes it with
// the key-value data and returns its address. The *next field is initialized to NULL
static Node *NewNode(uint32_t key, uint32_t value);

// Function creates a hash table on the heap and initializes the data array to
// the required capacity
HashTable *CreateHashTable(size_t capacity);

// Function takes a key and the capacity of the map and returns an integer matching
// the array index for the key which is a value between 0 and capacity-1
static size_t HashFunction(uint32_t key, size_t capacity);

// Function inserts an element to the table if it doesn't exist.
// If key exists, the value will be updated
void HashTableInsert(HashTable *hash_table, uint32_t key, uint32_t value);

// Function returns the value for the supplied key if the value exists, othewise
// it returns uint32_t MAX which is 4294967295 assuming that this value is invalid for
// your use case
uint32_t HashTableGet(HashTable *hash_table, uint32_t key);

// Deletes a key from the hash table and frees that section of memory
void HashTableDeleteKey(HashTable *hash_table, uint32_t key);

// Deletes the entire hash table and deallocates memory
void HashTableDeleteTable(HashTable *hash_table);

#endif