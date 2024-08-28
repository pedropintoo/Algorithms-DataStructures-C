///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

#include <assert.h>

// gcd(a,b) = gcd(b%a,a)
// gcd(0,b) = b
int gcd(int a, int b) {
    assert(a < b);

    if (a == 0) return b;
    return gcd(b%a,a);
}
