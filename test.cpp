#include <stdio.h>
#include <iostream>
#define N 9

int heap[N] = {7, 6, 5, 8, 3, 5, 9 ,1, 6};

void PRINT(int arr[]) {
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
}
void swap(int arr[], int a, int b) {
    int tmp;

    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main(void) {
    PRINT(heap);

    for (int i = 1; i < N; i++) {
        int target = i;
        do {
            int root = (target-1) / 2;
            if (heap[root] < heap[target])
                swap(heap, root, target);
            target = root;
        } while(target != 0);
    }

    for (int i = N-1; i >= 0; i--) {
        swap(heap, 0, i);

        int root = 0;
        int target = 1;
        do {
            target = 2*root + 1;
            if (heap[target] < heap[target+1] && target < i-1) target++;

            if (heap[root] < heap[target] && target < i)
                swap(heap, root, target);
            root = target;
        } while (target < i);
    }

    std::cout << '\n';
    PRINT(heap);

    return 0;
}