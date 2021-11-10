#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define N 6
#define W 52
#define IterN 20

int w[N+1] = { 0,2,10,13,17,22,42};
bool include[N+1];

int weight = 0;
int total = 0;

int TOTAL = 106;

int promising(int i) {
    return (weight+total >= W) && (weight == W || weight+w[i] <= W);
}
int MCE(int a) {
    int i;

    int m;
    int mProd;
    int totalNodes;

    int left, right;
    int randValue;

    Sleep(1000);

    srand(time(NULL));

    i = 0;
    totalNodes = 1;
    m = 1;
    mProd = 1;

    for (int j = 1; j <= N; j++) include[j] = false;

    while (m != 0 && i <= a) {
        mProd = mProd*m;
        totalNodes += mProd*a;
        i++;

        m = 0;

        weight = 0;
        for (int j = 1; j <= N; j++) {
            if (include[j])
                weight += w[j];
        }
        total = TOTAL - weight;

        left = 0;
        right = 0;

        weight += w[i];
        total -= w[i];

        if (promising(i)) {
            left = 1;
            m++;
        }
        weight -= w[i];
        total += w[i];

        total -= w[i];
        if (promising(i)) {
            right = 1;
            m++;
        }
        total += w[i];

        if (m != 0) {
            switch(m) {
                case 1:
                    if (left) randValue = 0;
                    else randValue = 1;
                    break;
                case 2:
                    randValue = rand() % 2;
                    break;
            }

            switch(randValue) {
                case 0:
                    weight += w[i];
                    total -= w[i];
                    include[i] = true;
                    break;
                case 1:
                    total -= w[i];
                    include[i] = false;
                    break;
            }
        }
    }
    return totalNodes;
}

int main() {
    int total = 0;
    int tmp;

    printf(">> Requiring Nodes for N = 6 <<\n");
    for (int i = 0; i < IterN; i++) {
        tmp = MCE(N);
        total += tmp;

        printf("%d >> %d nodes\n", i+1, tmp);
    }
        printf("-------------------------\n");
    printf(">> Average Nodes of the 20 Estimates <<\n");
    printf("%d nodes\n", total/IterN);

    return 0;
}