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

#define SIZE 20 // Maximum
u32 Comb_Cache[SIZE][SIZE];

void initCache(void) {
    for (size_t i = 0; i < SIZE; i++) 
        for (size_t j = 0; j < SIZE; j++) 
            Comb_Cache[i][j] = 0;
}

// C(n,p) = C(n-1,p-1) + C(n-1,p) , 0 < p < n
// C(n,p) = 1, p == 0 or p == n
int C_mem(int n, int p) {
    assert(n < SIZE);

    if (Comb_Cache[n][p] != 0) return Comb_Cache[n][p]; 
    
    u32 result; 

    if (p == 0 || p == n) result = 1;
    else result = C_mem(n-1,p-1) + C_mem(n-1,p);

    Comb_Cache[n][p] = result; // memoization

    return result;
}
