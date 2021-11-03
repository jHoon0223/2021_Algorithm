#include <stdio.h>

#define N 13

int set[11];

struct HEAP {
    int from;
    int to;
    int value;
};

int getParent(int index) {
    if (set[index] == index) return index;
    return getParent(set[index]);
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a<b) set[b] = a;
    else set[a] = b;
}
bool isCycle(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

int main() {
    struct HEAP H[N];
    H[0] = {4,8,3};
    H[1] = {8,9,4};
    H[2] = {3,7,5};
    H[3] = {6,10,6};
    H[4] = {4,5,10};
    H[5] = {9,10,12};
    H[6] = {1,4,17};
    H[7] = {3,4,18};
    H[8] = {5,9,25};
    H[9] = {5,6,28};
    H[10] = {1,2,32};
    H[11] = {2,5,45};
    H[12] = {7,8,59};

    for (int i = 0; i < 10; i++) {
        printf("(v%d, v%d) %d\n", H[i].from, H[i].to, H[i].value);
    }
    
    for (int i = 1; i < 10; i++) set[i] = i; 

    int total = 0;
    for (int i = 0; i < N; i++) {
        if (!isCycle(H[i].from, H[i].to)) {
            total += H[i].value;
            unionParent(H[i].from, H[i].to);
        }
    }

    printf("%d\n", total);

    return 0;
}