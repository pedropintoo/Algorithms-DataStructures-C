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

// O(n^2) comparisons
// O(n) swaps
void selection_sort(int a[], int n) {

	for (int k = n-1; k > 0; k--) {
		// max find
		int idxMax = 0;
		for (int i = 1; i <= k; i++) {
			if (a[i] >= a[idxMax]) idxMax = i;
		}
		// swap if different
		if (idxMax != k) swap(&a[idxMax], &a[k]);
	}
}
