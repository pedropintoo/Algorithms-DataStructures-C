///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// Delannoy's Sums Matrix - Recursive Function
// 0       0       0       0       0       0       0       0       0       0       0       
// 0       3       6       9       12      15      18      21      24      27      30      
// 0       6       18      36      60      90      126     168     216     270     330     
// 0       9       36      93      192     345     564     861     1248    1737    2340    
// 0       12      60      192     480     1020    1932    3360    5472    8460    12540   
// 0       15      90      345     1020    2523    5478    10773   19608   33543   54546   
// 0       18      126     564     1932    5478    13482   29736   60120   113274  201366  
// 0       21      168     861     3360    10773   29736   72957   162816  336213  650856  
// 0       24      216     1248    5472    19608   60120   162816  398592  897624  1884696 
// 0       27      270     1737    8460    33543   113274  336213  897624  2193843 4976166 
// 0       30      330     2340    12540   54546   201366  650856  1884696 4976166 12146178 


typedef long long unsigned u32;

// O(2^n)
u32 delannoy(int m, int n) {
    if (m*n == 0) return 1;

    return delannoy(m-1, n) + delannoy(m-1, n-1) + delannoy(m, n-1);
}
