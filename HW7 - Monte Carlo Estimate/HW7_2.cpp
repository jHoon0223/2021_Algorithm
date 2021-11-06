#include <stdio.h>

#define N 6
#define W 52

int w[N] = {2,10,13,17,22,42};
bool include[N];

void PRINT() {
    for (int i = 0; i < N; i++) {
        if (include[i] != false) printf("%d ", w[i]);
    }
    printf("\n");
}
bool promising(int i, int weight, int total) {
    return (weight+total >= W) && (weight == W || weight+w[i+1] <= W);
}
void SoS(int i, int weight, int total) {
    if (promising(i, weight, total)) {
        if (weight == W) {
            printf(">> Sum of 52 <<\n");
            PRINT();
            printf("---------------\n");
        }
        else {
            include[i+1] = true;
            SoS(i+1, weight+w[i+1], total-w[i+1]);
            include[i+1] = false;
            SoS(i+1, weight, total-w[i+1]);
        }
    }
    PRINT();
}

int main() {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += w[i];
        include[i] = false;
    }

    SoS(-1, 0, total);

    return 0;
}