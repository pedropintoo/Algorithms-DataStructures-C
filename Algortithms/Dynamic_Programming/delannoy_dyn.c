///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// Delannoy's Sums Matrix - Dynamic Function
// 0       0       0       0       0       0       0       0       0       0       0       
// 0       3       6       9       12      15      18      21      24      27      30      
// 0       6       12      18      24      30      36      42      48      54      60      
// 0       9       18      27      36      45      54      63      72      81      90      
// 0       12      24      36      48      60      72      84      96      108     120     
// 0       15      30      45      60      75      90      105     120     135     150     
// 0       18      36      54      72      90      108     126     144     162     180     
// 0       21      42      63      84      105     126     147     168     189     210     
// 0       24      48      72      96      120     144     168     192     216     240     
// 0       27      54      81      108     135     162     189     216     243     270     
// 0       30      60      90      120     150     180     210     240     270     300     

typedef long long unsigned u32;

// O(n)
u32 delannoy_dyn(int m, int n) {
    u32 del[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Base case
            if (i*j == 0) del[i][j] = 1;
            else del[i][j] = del[i-1][j] + del[i-1][j-1] + del[i][j-1];
        }
    }

    return del[m][n];
}