cmake_minimum_required(VERSION 3.14)
project(HashTable)

add_library(unity STATIC test/lib/Unity/src/unity.c)

include_directories(include)

add_executable(HashTable src/hash_table.c test/test.c)

target_link_libraries(HashTable unity)