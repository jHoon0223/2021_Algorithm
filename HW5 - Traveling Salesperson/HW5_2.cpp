#include <stdio.h>

#define N 4
#define INF 9999

int W[N][N] = { {0,2,9,INF},
                {1,0,6,4},
                {INF,7,0,8},
                {6,3,INF,0} };

int TSP(int W[N][N], int T[N], int start, int n) {
    int tmp[N];
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
        if (minCost > (W[T[start]][T[i]] + currCost))
            minCost = W[T[start]][T[i]] + currCost;
    }
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