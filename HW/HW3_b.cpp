#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

double arr[N], arr_SEL[N], arr_BUB[N], arr_INS[N],
        arr_MER[N], arr_QUI[N], arr_HEA[N], mergeSort[N];

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

void SelectionSort(double arr[]) {
    for (int i = N-1; i > 0; i--) {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
            maxIndex = arr[maxIndex] > arr[j] ? maxIndex : j;
        double tmp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = tmp;
    }
    PRINT(arr);
}
void BubbleSort(double arr[]) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 1; j < N; j++) {
            if (arr[j-1] > arr[j])
                swap(arr, j-1, j);          
        }
    }
    PRINT(arr);
}
void InsertionSort(double arr[]) {
    double target;
    int j;
    
    for (int i = 1; i < N; i++) {
        target = arr[i];
        for (j = i-1; j >= 0 && arr[j] > target; j--)
            arr[j+1] = arr[j];
        arr[j+1] = target;
    }
    PRINT(arr);
}

void Merge(double arr[], int left, int mid, int right) {
    int l = left;
    int r = mid+1;
    int index = left;

    while (l <= mid && r <= right) {
        if (arr[l] <= arr[r]) {
            mergeSort[index] = arr[l];
            index++;
            l++;
        }
        else {
            mergeSort[index] = arr[r];
            index++;
            r++;
        }
    }
    if (l > mid) {
        while (r <= right) {
            mergeSort[index] = arr[r];
            index++;
            r++;
        }
    }
    else {
        while(l <= mid) {
            mergeSort[index] = arr[l];
            index++;
            l++;
        }
    }

    for (int i = left; i <= right; i++)
        arr[i] = mergeSort[i];
}
void MergeSort(double arr[], int left, int right) {
    if (left == right) return;

    int mid = (left+right)/2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    Merge(arr, left, mid, right);
}

void QuickSort(double arr[], int start, int end) {
    if (start >= end) return;

    int pivot = start;

    int left = start+1;
    int right = end;

    while (left <= right) {
        while (arr[left] <= arr[pivot]) left++;
        while (arr[right] >= arr[pivot] && right > start) right--;

        if (left > right) swap(arr, right, pivot);
        else swap(arr, right, left);
    }
    QuickSort(arr, start, right-1);
    QuickSort(arr, right+1, end);
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
    double total_t_SEL, total_t_BUB, total_t_INS, 
            total_t_MER, total_t_QUI, total_t_HEA;

    for (int i = 0; i < N; i++) {
        double num = rand()%100 / 100.0 + rand()%2 - 1;
        arr[i] = num;
        arr_SEL[i] = num;
        arr_BUB[i] = num;
        arr_INS[i] = num;
        arr_MER[i] = num;
        arr_QUI[i] = num;
        arr_HEA[i] = num;
    }

    printf(">>>>> Array <<<<<\n");
    PRINT(arr);
    printf("\n");
    
    printf(">>>>> Selection Sort <<<<<\n");
    start_t = clock();
    SelectionSort(arr_SEL);
    end_t = clock();
    total_t_SEL = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> Bubble Sort <<<<<\n");    
    start_t = clock();
    BubbleSort(arr_BUB);
    end_t = clock();
    total_t_BUB = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> Insertion Sort <<<<<\n");    
    start_t = clock();
    InsertionSort(arr_INS);
    end_t = clock();
    total_t_INS = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> Merge Sort <<<<<\n");    
    start_t = clock();
    MergeSort(arr_MER, 0, N-1);
    PRINT(arr_MER);
    end_t = clock();
    total_t_MER = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> Quick Sort <<<<<\n");    
    start_t = clock();
    QuickSort(arr_QUI, 0, N-1);
    PRINT(arr_QUI);
    end_t = clock();
    total_t_QUI = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> Heap Sort <<<<<\n");    
    start_t = clock();
    HeapSort(arr_HEA);
    end_t = clock();
    total_t_HEA = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");

    printf(">>>>> TIME <<<<<\n");
    printf("When n is ( %d ), The execution time for each algorithm is as follows.\n", N);
    printf("----------------------------------------------------------------------\n");
    printf("Selection Sort : %f\n", total_t_SEL);
    printf("Bubble Sort : %f\n", total_t_BUB);
    printf("Insertion Sort : %f\n", total_t_INS);
    printf("Merge Sort : %f\n", total_t_MER);
    printf("Quick Sort : %f\n", total_t_QUI);
    printf("HEAP Sort : %f\n\n", total_t_HEA);

    return 0;
}