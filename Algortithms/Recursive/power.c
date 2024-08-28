///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long long unsigned u64;

// x^p = (x*x)^(p/2) * (if p%2 != 0: x ? 1), integer division
// Multiplications: O(log2(n))
u64 power(int x, int p) {
    if (p == 0) return 1;
    else if (p == 1) return x;
    
    u64 ret = power(x*x,p/2);
    
    return (p % 2 == 0) ? ret : x * ret;
}
