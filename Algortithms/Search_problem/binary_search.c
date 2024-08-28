///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

int binary_search(int a[], int n, int x) {
    int left = 0; int right = n - 1;
    while (left <= right) {
        int middle = (left + right)/2; // integer division
        if (a[middle] == x) return middle;
        if (a[middle] > x) right = middle - 1;
        else left = middle + 1;
    }
    return -1; // not found
}
