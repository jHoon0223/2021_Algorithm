#include <stdio.h>
#include <iostream>
#define N 8

using namespace std;

double arr[N], mergeSort[N];

void PRINT(double arr[]) {
    for (int i = 0; i < N; i++)
        printf("%.3f ", arr[i]);
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
        for (int j = 1; j < N-1; j++) {
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
    double tmp;

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
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    printf("-----------------------------------------\n");
    
    //SelectionSort(arr);
    //BubbleSort(arr);
    //InsertionSort(arr);
    /*MergeSort(arr, 0, N-1);
    PRINT(arr);*/
    /*QuickSort(arr, 0, N-1);
    PRINT(arr);*/
    HeapSort(arr);

    return 0;
}