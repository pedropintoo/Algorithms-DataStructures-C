///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long unsigned u32;

u32 coinProblem_dyn(int n, int* array) {

    u32 coinP[n+1];

    // Base cases
    coinP[0] = 0;
    coinP[1] = array[0];

    for (int i = 2; i <= n; i++) {
        int c1 = array[i-1] + coinP[i-2];
        int c2 = coinP[i-1];

        coinP[i] = c1 >= c2 ? c1 : c2;
    }

    return coinP[n];
}