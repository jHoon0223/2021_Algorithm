#include <stdio.h>

#define INF 99999
#define N 10

int W[N][N] = { {0,32,INF,17,INF,INF,INF,INF,INF,INF},
                {32,0,INF,INF,45,INF,INF,INF,INF,INF},
                {INF,INF,0,18,INF,INF,5,INF,INF,INF},
                {17,INF,18,0,10,INF,INF,3,INF,INF},
                {INF,45,INF,10,0,28,INF,INF,25,INF},
                {INF,INF,INF,INF,28,0,INF,INF,INF,6},
                {INF,INF,5,INF,INF,INF,0,59,INF,INF},
                {INF,INF,INF,3,INF,INF,59,0,4,INF},
                {INF,INF,INF,INF,25,INF,INF,4,0,12},
                {INF,INF,INF,INF,INF,6,INF,INF,12,0} };
                //인접행렬
int nearest[N]; //정점 중에서 Vi와 가장 가까운 정점
int distance[N];//Vi와 nearest를 잇는 이음선의 가중치

int minVertex() {
    int vertex;

    for (int i = 0; i < N; i++) {
        if (!nearest[i]) {
            vertex = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!nearest[i] && (distance[i] < distance[vertex]))
            vertex = i;
    }   //선택하지 않은 간선들 중 최소 가중치 값을 갖는 정점을 찾는다.

    return vertex;
}   //최소 distance값을 갖는 정점을 반환
void PRIMS() {
    int index;

    for (int index = 0; index < N; index++)
        distance[index] = INF;
    distance[0] = 0;
    //시작점. 문제 1번은 시작점이 V1

    for (int i = 0; i < N; i++) {
        index = minVertex();
        nearest[index] = -1;    //지나간 경로 체크

        if (distance[index] == INF) return;

        printf("%d ", index+1);

        for (int v = 0; v < N; v++) {
            if (W[index][v] != INF) {
                if (!nearest[v] && W[index][v] < distance[v])
                    distance[v] = W[index][v];
            }
        }
    }
}
void PRINT() {
    printf("Adjacent Matrix >> \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", W[i][j]);
        }
        printf("\n");
    }
}   //출력 함수

int main() {
    printf(">> Prim's Algorithm <<\n");
    printf("-------------------------\n");
    PRINT();
    printf("-------------------------\n");

    printf("Minimum Spanning Tree >> \n"); 
    PRIMS();

    return 0;
}