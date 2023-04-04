#include <stdio.h>
#include "lib/Unity/src/unity.h"
#include "../includes/hash_table.h"

void setUp(void) {}

void tearDown(void) {}

void test_CreateHashTable(void)
{
    int capacity = 128;
    HashTable *ht = CreateHashTable(capacity);
    TEST_ASSERT_NOT_NULL(ht);
    TEST_ASSERT_EQUAL_INT(ht->capacity, capacity);
    TEST_ASSERT_EQUAL_INT(sizeof(ht->data[0]) * ht->capacity, capacity * sizeof(Node *));
}

void test_HashTable_Insert_Get_DeleteKey(void)
{
    int capacity = 128;
    HashTable *ht = CreateHashTable(capacity);
    HashTableInsert(ht, 222, 333);
    HashTableInsert(ht, 111, 555);

    TEST_ASSERT_EQUAL_INT(HashTableGet(ht, 222), 333);
    TEST_ASSERT_EQUAL_INT(HashTableGet(ht, 111), 555);
    TEST_ASSERT_EQUAL_INT(HashTableGet(ht, 99), UINT32_MAX);

    HashTableDeleteKey(ht, 222);
    TEST_ASSERT_EQUAL_INT(HashTableGet(ht, 222), UINT32_MAX);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_CreateHashTable);
    RUN_TEST(test_HashTable_Insert_Get_DeleteKey);
    return UNITY_END();
}