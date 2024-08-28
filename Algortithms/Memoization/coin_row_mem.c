///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long unsigned u32;

#define SIZE 1025
u32 coinP_Cache[SIZE];

void initializeCache() {
    for (unsigned int i = 0; i < SIZE; i++)
        coinP_Cache[i] = 0;
}

u32 coinProblem_memoization(int n, int* array) {

    if (coinP_Cache[n] != 0) return coinP_Cache[n]; 

    u32 result;
    if (n == 0) result = 0;
    if (n == 1) result = array[0];
    else {
        u32 c1 = array[n-1] + coinProblem_memoization(n-2, array);
        u32 c2 = coinProblem_memoization(n-1, array);

        result = c1 >= c2 ? c1 : c2;
    }

    coinP_Cache[n] = result; // memoization

    return result;
}