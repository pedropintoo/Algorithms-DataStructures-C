///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// C(n,p) = C(n-1,p-1) + C(n-1,p) , 0 < p < n
// C(n,p) = 0, p < 0 or p > n
// C(n,p) = 1, p == 0 or p == n
int C(int n, int p) {
    if (p < 0 || p > n) return 0;
    if (p == 0 || p == n) return 1;

    return C(n-1,p-1) + C(n-1,p);
}
