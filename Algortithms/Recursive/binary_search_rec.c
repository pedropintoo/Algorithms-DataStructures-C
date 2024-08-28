///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// Recursions: O(log2(n))
int binary_search_rec(int a[], int left, int right, int value) {
    if (left > right) return -1; // not found

    unsigned int middle = (right+left)/2;

    if (a[middle] == value) return middle;

    if (a[middle] > value) {
        rec_binary_search(a, left, middle-1, value);
    }

    return  rec_binary_search(a, middle+1, right, value);
}