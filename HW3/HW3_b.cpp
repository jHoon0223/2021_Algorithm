#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000  //n값 정의

double arr[N], arr_SEL[N], arr_BUB[N], arr_INS[N],
        arr_MER[N], arr_QUI[N], arr_HEA[N], mergeSort[N];
        //각 Sorting Algorithm에 따라 다른 배열에 저장

void PRINT(double arr[]) {
    for (int i = 0; i < N; i++)
        printf("%.3f ", arr[i]);
    printf("\n");
}   //배열 프린트 함수
void swap(double arr[], int a, int b) {
    double tmp;

    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}   //두 값 swap

void SelectionSort(double arr[]) {
    for (int i = N-1; i > 0; i--) {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
            maxIndex = arr[maxIndex] > arr[j] ? maxIndex : j;
            //가장 큰 값을 찾아 maxIndex에 넣어줌
        swap(arr, maxIndex, i);
        //찾은 maxIndex와 맨 마지막 값 swap
    }
    PRINT(arr);
}   //선택정렬
void BubbleSort(double arr[]) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 1; j < N; j++) {
            if (arr[j-1] > arr[j])
                swap(arr, j-1, j);
                //모든 인덱스를 탐색하여 조건에 맞게 swap        
        }
    }
    PRINT(arr);
}   //버블정렬
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
}   //삽입 정렬

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
    }   //분할된 배열들을 다시 병합
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
    }   //아직 남아있는 값들을 다시 복사

    for (int i = left; i <= right; i++)
        arr[i] = mergeSort[i];
        //mergeSort (임시 배열) 에 저장되어 있는 인덱스들을 다시 원래 배열로 복사
}   //병합정렬에 필요한 merge 함수
void MergeSort(double arr[], int left, int right) {
    if (left == right) return;

    int mid = (left+right)/2;   //중간 값 정의

    MergeSort(arr, left, mid);  //앞부분 분할하여 정렬
    MergeSort(arr, mid+1, right);   //뒷부분 분할하여 정렬

    Merge(arr, left, mid, right);   //분할 된 배열들을 다시 병합
}   //병합정렬 함수

void QuickSort(double arr[], int start, int end) {
    if (start >= end) return;
    //start의 위치가 더 큰 경우, 바로 return

    int pivot = start;  //pivot값 지정

    int left = start+1;
    int right = end;

    while (left <= right) {
        while (arr[left] <= arr[pivot]) left++;
        while (arr[right] >= arr[pivot] && right > start) right--;

        if (left > right) swap(arr, right, pivot);
        else swap(arr, right, left);
    }   //엇갈릴때 까지 반복하며 swap함수를 이용하여 정렬

    QuickSort(arr, start, right-1); //다시 앞부분 분할하여 정렬
    QuickSort(arr, right+1, end);   //다시 뒷부분 분할하여 정렬
}
void HeapSort(double arr[]) {
    for (int i = 1; i < N; i++) {
        int target = i; //타겟 지정
        do {
            int root = (target-1) / 2;
            if (arr[root] < arr[target])
                swap(arr, root, target);
            target = root;
        } while(target != 0);
    }   //배열에 담겨있는 값을 적절한 조건에 맞게 힙으로 구성 - Heapify

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
    }   //Heapify 코드와 유사하게 계속해서 힙을 구성하며 정렬
    PRINT(arr);
}

int main(void) {
    clock_t start_t, end_t;
    double total_t_SEL, total_t_BUB, total_t_INS, 
            total_t_MER, total_t_QUI, total_t_HEA;
            //Execution Time을 측정하기 위한 변수

    for (int i = 0; i < N; i++) {
        double num = rand()%100 / 100.0 + rand()%2 - 1;
        arr[i] = num;
        arr_SEL[i] = num;
        arr_BUB[i] = num;
        arr_INS[i] = num;
        arr_MER[i] = num;
        arr_QUI[i] = num;
        arr_HEA[i] = num;
    }   //난수를 발생시켜 각 배열에 배정.
        //각 배열의 초깃값은 같은 인덱스들로 초기화 됨

    printf(">>>>> Array <<<<<\n");
    PRINT(arr);
    printf("\n");
    
    printf(">>>>> Selection Sort <<<<<\n");
    start_t = clock();
    SelectionSort(arr_SEL);
    end_t = clock();
    total_t_SEL = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    //end_t에서 start_t를 빼주면 sorting 함수에서 걸린 수행시간 측정 가능
    //total_t 변수에 수행시간 저장. 아래도 같은 방법으로 수행
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
    printf("Selection Sort : %.3f ms\n", total_t_SEL);
    printf("Bubble Sort : %.3f ms\n", total_t_BUB);
    printf("Insertion Sort : %.3f ms\n", total_t_INS);
    printf("Merge Sort : %.3f ms\n", total_t_MER);
    printf("Quick Sort : %.3f ms\n", total_t_QUI);
    printf("HEAP Sort : %.3f ms\n\n", total_t_HEA);
    //n에 따른 sorting Algorithm의 수행시간 출력

    return 0;
}