#include <stdio.h>
#include <iostream>
#define N 8

using namespace std;

int arr_SEL[N] = {12,30,21,55,25,72,45,50};
int arr_BUB[N] = {12,30,21,55,25,72,45,50};
int arr_INS[N] = {12,30,21,55,25,72,45,50};
int arr_MER[N] = {12,30,21,55,25,72,45,50};
int arr_QUI[N] = {12,30,21,55,25,72,45,50};
int arr_HEA[N] = {12,30,21,55,25,72,45,50};
int mergeSort[N];

void PRINT(int arr[]) {
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int arr[], int a, int b) {
    int tmp;

    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void SelectionSort(int arr[]) {
    for (int i = N-1; i > 0; i--) {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
            maxIndex = arr[maxIndex] > arr[j] ? maxIndex : j;
        int tmp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = tmp;

        PRINT(arr);
    }    
}
void BubbleSort(int arr[]) {
    for (int i = 0; i < N-1; i++) {        
        for (int j = 1; j < N; j++) {
            if (arr[j-1] > arr[j])
                swap(arr, j-1, j);          
        }
        PRINT(arr);
    }    
}
void InsertionSort(int arr[]) {
    int target;
    int j;
    
    for (int i = 1; i < N; i++) {
        target = arr[i];
        for (j = i-1; j >= 0 && arr[j] > target; j--)
            arr[j+1] = arr[j];
        arr[j+1] = target;

        PRINT(arr);
    }    
}

void Merge(int arr[], int left, int mid, int right) {
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

    PRINT(arr);
}
void MergeSort(int arr[], int left, int right) {
    if (left == right) return;

    int mid = (left+right)/2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    Merge(arr, left, mid, right);
}

void QuickSort(int arr[], int start, int end) {
    PRINT(arr);

    if (start >= end) return;

    int pivot = start;

    int left = start+1;
    int right = end;
    int tmp;

    while (left <= right) {
        while (arr[left] <= arr[pivot]) left++;
        while (arr[right] >= arr[pivot] && right > start) right--;

        if (left > right) swap(arr, right, pivot);
        else swap(arr, right, left);
    }
    QuickSort(arr, start, right-1);
    QuickSort(arr, right+1, end);
}
void HeapSort(int arr[]) {
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

        PRINT(arr);
    }    
}

int main(void) {
    printf(">>>>> Array <<<<<\n");
    PRINT(arr_SEL);
    printf("\n");
    
    printf(">>>>> Selection Sort <<<<<\n");    
    SelectionSort(arr_SEL);
    printf("\n");

    printf(">>>>> Bubble Sort <<<<<\n");    
    BubbleSort(arr_BUB);
    printf("\n");

    printf(">>>>> Insertion Sort <<<<<\n");    
    InsertionSort(arr_INS);
    printf("\n");

    printf(">>>>> Merge Sort <<<<<\n");    
    MergeSort(arr_MER, 0, N-1);
    printf("\n");

    printf(">>>>> Quick Sort <<<<<\n");    
    QuickSort(arr_QUI, 0, N-1);
    printf("\n");

    printf(">>>>> Heap Sort <<<<<\n");    
    HeapSort(arr_HEA);
    printf("\n");

    //SelectionSort(arr);
    
    //InsertionSort(arr);
    /*MergeSort(arr, 0, N-1);
    PRINT(arr);*/
    /*QuickSort(arr, 0, N-1);
    PRINT(arr);*/
    //HeapSort(arr);

    return 0;
}