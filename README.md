# Hash Table for Embedded Systems

# About the project

This project presents a hash table library which can be used to store key-value pairs for use in memory-constrained embedded systems. The elements in the hash table are not ordered.

The hash table library provides three functionalities:
- Add a key-value pair to the hash table
- Get the value that matches a certain key
- Delete an item from the hash table

The underlying implementation for the hash table is an array and elements are chained in a linked list at each array index for handling hash collisions. Incase an element exists in the hash table, its value will be updated to the new one.

The default data type for the key and value is `uint32_t`. To use different data types, the library can be modified for use as explained [here](#usage).

> **Note:** The function to get an element from the hash table will return `UINT32_MAX` which is assumed to be invalid for most situations. You can make adjustments accordingly.

## Built with:
 - C
 - CMake

# Getting Started

## Prerequisites  

- `C` compiler

## Installation
1. Clone the repo with
```
git clone https://github.com/denis-mutuma/hash-table.git
```

2. In the project folder:
   -  `cd build`
   -  `cmake ..`
   -  `cmake --build .`

3. If you make changes to the source code, write custom unit tests, repeat step 2 and run the tests with by running the executable `HashTable` in the `build` folder. In this project, the [Unity](https://github.com/ThrowTheSwitch/Unity) testing framework was used. You can download it and uzip it in the `test/lib/Unity` folder.

# Usage

```
// Create a Hash Table as follows with a specified size e.g., 256
HashTable *ht = CreateHashTable(256);

// Verify the hash table was created in memory, reduce the hash table size and try again
if(!ht) {
    // try again
    // unsufficient memory?
}

// Add key-value pairs to the hash table
HashTableInsert(ht, 22, 11);
HashTableInsert(ht, 80, 170);
    .
    .
    .
HashTableInsert(ht, 67, 213);

// Get elements from the hash table and verify that it is valid
uint32_t value = HashTableGet(80);
if(value != UINT32_MAX) {
    // do something with the value
}

// Delete a key-value pair if necessary
HashTableDeleteKey(ht, 67);

// Be sure to cleanup when done to avoid memory leaks
HashTableDeleteTable(ht);
```


To modify the hash table library to store e.g., `uint16_t`, proceed as follows:

Change the `key` and `value` fields of the `Node` struct from:

```
typedef struct
{
    uint32_t key;
    uint32_t value;
    struct Node *next;
} Node;
```
to:

```
typedef struct
{
    uint16_t key;
    uint16_t value;
    struct Node *next;
} Node
```

Proceed to change othe functions in the header file and source file to match the desired type.

# Contributing

1. Fork the Project

2. Create your Feature Branch (git checkout -b feature/AmazingFeature)

3. Commit your Changes (git commit -m 'Add some AmazingFeature')

4. Push to the Branch (git push origin feature/AmazingFeature)

5. Open a Pull Request

# License

Distributed under the **BSD** License.