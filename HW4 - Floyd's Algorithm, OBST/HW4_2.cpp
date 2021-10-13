#include <stdio.h>

#define N 8
#define INF 99999
const int W[N][N] = { {0,0,0,0,0,0,0,0},
                    {0,0,INF,INF,INF,INF,10},
                    {0,INF,0,1,12,INF,INF,INF},
                    {0,19,2,0,15,5,INF,5},
                    {0,INF,INF,INF,0,6,INF,INF},
                    {0,INF,INF,18,INF,0,3,INF},
                    {0,10,INF,INF,INF,4,0,INF},
                    {0,INF,INF,8,INF,INF,INF,0} };
int P[N][N];
int D[N][N];
//W : 가중치 포함 그래프
//P : 정점의 가장 큰 인덱스 행렬
//D : 최단경로 행렬

void Floyd(int n, const int W[N][N], int D[N][N], int P[N][N]) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            P[i][j] = 0;
        }
    }   //0으로 초기화

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            D[i][j] = W[i][j];
        }
    }   //D = W

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }   //경로의 최솟값을 찾아 행렬에 저장
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
}   //최단 경로 계산 후 출력
void PRINT(const int arr[N][N]) {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}   //행렬 출력

int main() {
    Floyd(N, W, D, P);
    
    //PRINT(W);
    PRINT(D);
    PRINT(P);

    Path(7, 4);

    return 0;
}