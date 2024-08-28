///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long unsigned u32;

// f(0) = 0
// f(1) = 1
// f(n) = f(n-1) + f(n-2)
// Sums: O(n)
u32 fib_dp(int n) {
    u32 fib[n+1]; // dynamic recursion

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}
