#ifndef K_UTILS_H_
#define K_UTILS_H_

// #include <stdio.h>
#include <stdlib.h>

void die(const char*, ...);

// memory allocations
void* safe_malloc(size_t);
void* safe_calloc(size_t, size_t);

// string operations
#endif // K_UTILS_H_
