///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long unsigned u32;

u32 coinProblem(int n, int* array) {
    if (n == 0) return 0;
    if (n == 1) return array[0];

    u32 c1 = array[n-1] + coinProblem_recursive(n-2, array);
    u32 c2 = coinProblem_recursive(n-1, array);
    return c1 >= c2 ? c1 : c2; // array[n-1] must be in the solution?
}