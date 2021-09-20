#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define N 100

double heap[N];

void PRINT(double arr[]) {
    for (int i = 0; i < N; i++)
        printf("%.3f ", arr[i]);
    printf("\n");
}
void swap(double arr[], int a, int b) {
    double tmp;

    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void HeapSort(double arr[]) {
    for (int i = 1; i < N; i++) {
        int target = i;
        do {
            int root = (target-1) / 2;
            if (arr[root] < arr[target])
                swap(arr, root, target);
            target = root;
        } while(target != 0);
    }

    for (int i = N-1; i >= 0; i--) {
        swap(arr, 0, i);

        int root = 0;
        int target = 1;
        do {
            target = 2*root + 1;
            if (arr[target] < arr[target+1] && target < i-1) target++;

            if (arr[root] < arr[target] && target < i)
                swap(arr, root, target);
            root = target;
        } while (target < i);
    }
    PRINT(arr);
}

int main(void) {
    clock_t start_t, end_t;
    double total_t;

    for (int i = 0; i < N; i++)
        heap[i] = rand()%100 / 100.0 + rand()%2 - 1;

    PRINT(heap);

    start_t = clock();
    HeapSort(heap);
    end_t = clock();

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("%f", total_t);

    return 0;
}