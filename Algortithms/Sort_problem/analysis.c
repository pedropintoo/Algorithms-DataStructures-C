///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

// Output:
//                  Sorted list                                 Reverse Sorted list                                 Random list
//    Sel. sort   Bub. sort   Ins. sort               Sel. sort   Bub. sort   Ins. sort               Sel. sort   Bub. sort   Ins. sort       
//        0.000       0.000       0.000                   0.000       0.000       0.000                   0.000       0.000       0.000
//        0.000       0.000       0.000                   0.000       0.000       0.000                   0.000       0.000       0.000
//        0.001       0.001       0.001                   0.001       0.000       0.000                   0.001       0.001       0.000
//        0.078       0.116       0.050                   0.084       0.000       0.000                   0.080       0.122       0.025
//        8.549      11.881       5.133                   8.520       0.000       0.000                   8.733      18.561       2.463



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef void (*SortFunction)(int*, int);

void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);
void insertion_sort(int a[], int n);

#define VERSIONS 3  // Versions of sorting algorithms
#define N_MAX 1000000

SortFunction analysis_algorithms[VERSIONS] = {
    selection_sort,
    bubble_sort,
    insertion_sort
};

char* analysis_names[VERSIONS] = {
    "Sel. sort",
    "Bub. sort",
    "Ins. sort"
};

int main () {
    int DEMOS = 3;  // Different characteristic test arrays

    // Header
    printf("\n\n%28s\t\t%40s\t\t%28s\n","Sorted list", "Reverse Sorted list", "Random list");
    for (int d = 0; d < DEMOS; d++) printf("%12s%12s%12s%8s","Sel. sort","Bub. sort","Ins. sort",d<DEMOS-1 ? "\t" : "\n");

    for (size_t n = 10; n < N_MAX; n*=10) {
        size_t size = n*sizeof(int);

        // Sorted array (demo 1)
        int* sorted_array = malloc(size);
        for (size_t i = 0; i < n; i++) sorted_array[i] = i;
        
        // Reverse Sorted array (demo 2)
        int* revSorted_array = malloc(size);
        for (size_t i = 0; i < n; i++) sorted_array[i] = (n-1)-i;

        // Random array (demo 3)
        srand(time(NULL));
        int* rand_array = malloc(size);
        for (size_t i = 0; i < n; i++) rand_array[i] = rand() % n;

        // Start testing demos
        int* demo_arrays[] = {sorted_array, revSorted_array, rand_array};

        for (size_t i = 0; i < DEMOS; i++) {
            for (size_t v = 0; v < VERSIONS; v++) {
                // Copy array for testing in all versions
                int* test_array = malloc(size);
                memcpy(test_array,demo_arrays[i],size);

                SortFunction func = analysis_algorithms[v];
                
                // Counting the time
                clock_t begin = clock();
                func(test_array,n);
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("%12.3f",time_spent);

                free(test_array);
            }
            printf("\t\t");
        }
        printf("\n");

        free(sorted_array);
        free(revSorted_array);
        free(rand_array);
    }
    printf("\n\n");
}


// DEFINITIONS

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

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

