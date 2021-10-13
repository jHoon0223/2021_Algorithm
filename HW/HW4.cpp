#include <stdio.h>

#define N 8
#define INF 99999
const int W[N][N] = { {0,0,0,0,0,0,0,0},
                {0,0,4,INF,INF,INF,10,INF,},
                {0,3,0,INF,18,INF,INF,INF},
                {0,INF,6,0,INF,INF,INF,INF},
                {0,INF,5,15,0,2,19,5},
                {0,INF,INF,12,1,0,INF,INF},
                {0,INF,INF,INF,INF,INF,0,10},
                {0,INF,INF,INF,8,INF,INF,0} };
int P[N][N];
int D[N][N];

void Floyd(int n, const int W[N][N], int D[N][N], int P[N][N]) {
    int i, j, k;

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            P[i][j] = 0;
        }
    }

    for (i = 1; i < N; i++) {
        for (j = 1; j < N; j++) {
            D[i][j] = W[i][j];
        }
    }

    for (k = 1; k < n; k++) {
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}
void Path(int a, int b) {
    printf("path(%d,%d) = %d\n", a, b, P[a][b]);

    if (P[a][b] != 0) {
        Path(a, P[a][b]);
        printf("v%d \n", P[a][b]);
        Path(P[a][b], b);
    }
}
void PRINT(const int arr[N][N]) {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

int main() {
    Floyd(N, W, D, P);
    
    PRINT(W);
    PRINT(D);
    PRINT(P);

    Path(1, 3);

    return 0;
}