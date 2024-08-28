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

typedef long long unsigned u32;

#define SIZE 12 // Maximum
u32 Del_Cache[SIZE][SIZE];

void initializeCache() {
    for (size_t i = 0; i < SIZE; i++)
        for (size_t j = 0; j < SIZE; j++)
            Del_Cache[i][j] = 0;
}

u32 delannoy_mem(int m, int n) {
    if (Del_Cache[m][n] != 0) return Del_Cache[m][n];

    // Base cases
    u32 result;
    if(m*n == 0) result = 1;
    else result = delannoy_mem(m-1, n) + delannoy_mem(m-1, n-1) + delannoy_mem(m, n-1);

    Del_Cache[m][n] = result;

    return result;
}