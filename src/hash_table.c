#include <stdlib.h>
#include <stdint.h>

#include "../includes/hash_table.h"

static Node *NewNode(uint32_t key, uint32_t value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        return NULL;
    }
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

HashTable *CreateHashTable(size_t capacity)
{
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
    if (!hash_table)
    {
        return NULL;
    }
    hash_table->capacity = capacity;
    hash_table->data = calloc(hash_table->capacity, sizeof(Node *));
    if (!hash_table->data)
    {
        return NULL;
    }
    return hash_table;
}

static size_t HashFunction(uint32_t key, size_t capacity)
{
    return key % capacity;
}

void HashTableInsert(HashTable *hash_table, uint32_t key, uint32_t value)
{
    size_t index = HashFunction(key, hash_table->capacity);
    Node *head = hash_table->data[index];
    if (head == NULL)
    {
        hash_table->data[index] = NewNode(key, value);
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = head;
        while (curr != NULL)
        {
            if (curr->key == key)
            {
                curr->value = value;
                return;
            }
            prev = curr;
            curr = (Node *)curr->next;
        }
        prev->next = (struct Node *)NewNode(key, value);
        return;
    }
}

uint32_t HashTableGet(HashTable *hash_table, uint32_t key)
{
    size_t index = HashFunction(key, hash_table->capacity);
    Node *head = hash_table->data[index];
    if (head == NULL)
    {
        return UINT32_MAX;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = (Node *)temp->next;
    }
    return UINT32_MAX;
}

void HashTableDeleteKey(HashTable *hash_table, uint32_t key)
{
    size_t index = HashFunction(key, hash_table->capacity);
    Node *head = hash_table->data[index];
    if (head == NULL)
    {
        return;
    }

    Node *prev = head;
    Node *next = head;
    Node *curr = head;
    while (curr != NULL)
    {
        next = (Node *)curr->next;
        if (curr->key == key)
        {
            if (curr == head)
            {
                hash_table->data[index] = next;
            }
            else
            {
                prev->next = (struct Node *)next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = (Node *)curr->next;
    }
}

void HashTableDeleteTable(HashTable *hash_table)
{
    for (size_t i = 0; i < hash_table->capacity; ++i)
    {
        Node *head = hash_table->data[i];
        while (head != NULL)
        {
            Node *temp = head;
            head = (Node *)head->next;
            free(temp);
            temp = NULL;
        }
    }

    free(hash_table->data);
    hash_table->data = NULL;

    free(hash_table);
    hash_table = NULL;
}