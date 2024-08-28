///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// f(0) = 0
// f(1) = 1
// f(n) = f(n-1) + f(n-2)
int fibonacci(int n) {
    if (n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}
