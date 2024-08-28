///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// Comparisons: B(n) = n-1 / W(n) = O(n^2)
// Shifts: B(n) = 0 / W(n) = O(n^2)
void insertion_sort(int a[], int n) {
    for (int k = 1 ; k < n; k++) {
        // sorted list: [0,k]
        int i, elem = a[k];
        for(i = k-1; i >= 0 && elem < a[i]; i--) {
            a[i+1] = a[i]; // right shift
        }
        a[i+1] = elem;
    }
}
