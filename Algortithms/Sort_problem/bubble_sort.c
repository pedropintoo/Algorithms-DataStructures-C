///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Comparisons: B(n) = n-1 / W(n) = O(n^2)
// Swaps: B(n) = 0 / W(n) = O(n^2)
void bubble_sort(int a[], int n) {
    int swapped = 1;
    for (int k = n-1; swapped; k--){
        swapped = 0;
        // swap if greater
        for (int i = 0; i < k; i++) {
            if (a[i] > a[i+1]) {
                swap(&a[i],&a[i+1]);
                swapped = 1; // check already sorted array
            }
        }
    }
}
