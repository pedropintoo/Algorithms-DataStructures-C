///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

typedef long unsigned u32;

// C(n,p) = C(n-1,p-1) + C(n-1,p) , 0 < p < n
// C(n,p) = 1, p == 0 or p == n
int C_dp(int n, int p) {
    if (p == 0 || p == n) return 1; // more efficient!
    
    u32 comb[n+1][n+1]; // dynamic recursion

    for (int i = 0; i <= n; i++) {
        // Base cases
        comb[i][0] = 1; // C(n,0) = 1;
        comb[i][i] = 1; // C(n,n) = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }

    return comb[n][p];
}
