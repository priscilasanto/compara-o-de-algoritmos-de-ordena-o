#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

#define NUM_SIZES 9
int sizes[NUM_SIZES] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};

void copy_array(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void run_tests() {
    FILE *f = fopen("tempos.csv", "w");
    fprintf(f, "Tamanho,Bubble,Selection,Insertion,Merge,Quick,Counting\n");

    for (int i = 0; i < NUM_SIZES; i++) {
        int n = sizes[i];
        int *original = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) original[j] = rand() % 100000;

        int *arr = malloc(n * sizeof(int));
        clock_t start, end;
        double t[6];

        copy_array(original, arr, n);
        start = clock(); bubble_sort(arr, n); end = clock(); t[0] = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(original, arr, n);
        start = clock(); selection_sort(arr, n); end = clock(); t[1] = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(original, arr, n);
        start = clock(); insertion_sort(arr, n); end = clock(); t[2] = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(original, arr, n);
        start = clock(); merge_sort(arr, 0, n - 1); end = clock(); t[3] = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(original, arr, n);
        start = clock(); quick_sort(arr, 0, n - 1); end = clock(); t[4] = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(original, arr, n);
        start = clock(); counting_sort(arr, n); end = clock(); t[5] = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(f, "%d,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n", n, t[0], t[1], t[2], t[3], t[4], t[5]);

        free(original); free(arr);
    }

    fclose(f);
}

int main() {
    srand(time(NULL));
    run_tests();
    return 0;
}