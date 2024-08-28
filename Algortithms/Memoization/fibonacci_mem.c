///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

#include <stdlib.h>
#include <assert.h>

typedef long unsigned u32;

#define SIZE 100 // Maximum
u32 Fib_Cache[SIZE];

void initCache(void) {
    for (size_t i = 0; i < SIZE; i++) Fib_Cache[i] = 0;
}

// f(0) = 0
// f(1) = 1
// f(n) = f(n-1) + f(n-2)
u32 fib_mem(int n) {
    assert(n < SIZE);

    if (Fib_Cache[n] != 0) return Fib_Cache[n]; 

    u32 result;
    if (n <= 1) result = n;
    else result = fib_mem(n-1) + fib_mem(n-2);

    Fib_Cache[n] = result; // memoization

    return result;
}
