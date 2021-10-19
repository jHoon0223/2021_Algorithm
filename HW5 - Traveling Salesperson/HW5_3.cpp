#include <stdio.h>

#define N 7
#define INF 9999

int W[N][N] = { {0,4,INF,INF,INF,10,INF,},
                {3,0,INF,18,INF,INF,INF},
                {INF,6,0,INF,INF,INF,INF},
                {INF,5,15,0,2,19,5},
                {INF,INF,12,1,0,INF,INF},
                {INF,INF,INF,INF,INF,0,10},
                {INF,INF,INF,8,INF,INF,0} };

int TSP(int W[N][N], int T[N], int start, int n) {
    int tmp[N], minT[N];
    int minCost, currCost;

    if (start == n-2)
        return W[T[n-2]][T[n-1]] + W[T[n-1]][0];

    minCost = INF;

    for (int i = start+1; i < n; i++) {
        for (int j = 0; j < n; j++)
            tmp[j] = T[j];
        
        tmp[start+1] = T[i];
        tmp[i] = T[start+1];

        currCost = TSP(W, tmp, start+1, n);
        if (minCost > (W[T[start]][T[i]] + currCost)) {
            minCost = W[T[start]][T[i]] + currCost;

            for (int k = 0; k < N; k++)
                minT[k] = tmp[k];
        }       
    }
    for (int k = 0; k < N; k++)
        T[k] = minT[k];

    return minCost;
}

int main() {
    int total;
    int T[N];

    for (int i = 0; i < N; i++)
        T[i] = i;

    total = TSP(W, T, 0, N);

    printf(">> 牢立 青纺 <<\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", W[i][j]);
        printf("\n");
    }

    printf("\n弥家 Cost >> %d\n", total);

    printf("\n弥利 老林 版肺 >> ");
    for (int i = 0; i < N; i++)
        printf("%d ", T[i] + 1);
    printf("1\n");

    return 0;
}