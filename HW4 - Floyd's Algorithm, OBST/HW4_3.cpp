#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

typedef struct NODE {
    struct NODE* left;
    struct NODE* right;
    char key[10];
} node;     //그래프로 만들기 위한 구조체

double A[N][N];
int R[N][N];
const double P[7] = { 0, 0.05, 0.15, 0.05, 0.35, 0.05, 0.35 };
const char KEY[6][10] = { {"CASE"},{"ELSE"},{"END"},{"IF"},{"OF"},{"THEN"} };
//A : Optimal Binary Search Tree 의 경로
//R : 최솟값을 갖는 k값 저장
//P : KEY값들의 발생빈도
//KEY : KEY값

double SUM(int begin, int end) {
    double total = 0;
    for (int i = begin; i <= end; i++) total += P[i];
    return total;
}   //입력된 index를 기준으로 Key값들을 순회하며 sum값 return
void OBST(int n) {
    double min;

    for (int i = 1; i <= n; i++) {
        A[i][i-1] = 0;
        A[i][i] = P[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    A[n+1][n] = 0;
    R[n+1][n] = 0;

    for (int dig = 1; dig <= n-1; dig++) {
        for (int i = 1; i <= n-dig; i++) {
            int j = i + dig;
            min = A[i][i-1] + A[i+1][j] + SUM(i,j);

            for (int k = i; k <= j; k++) {
                if (min >= A[i][k-1] + A[k+1][j] + SUM(i,j)) {
                    min = A[i][k-1] + A[k+1][j] + SUM(i, j);
                    R[i][j] = k;
                }
            }
            A[i][j] = min;
        }
    }
}   //Optimal Binary Search Tree Algorithm
node* TREE(int i, int j) {
    int k = R[i][j];
    if (k == 0) return NULL;
    else {
        node* p = (node*)malloc(sizeof(node));
        strcpy(p->key, KEY[k-1]);
        p->left = TREE(i, k-1);
        p->right = TREE(k+1, j);
        return p;
    }
}   //트리 구성 함수. 재귀적 구조로 정의하여 한번에 구성될 수 있도록 한다.

void PRINT(double arr[N][N], char c) {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            printf("%c[%d][%d] : %.2f\n", c, i, j, arr[i][j]);
        }
    }
    printf("-------------------------\n");
}
void PRINT_TREE(node* head) {
    if (head == NULL) return;
    else {
        printf("[%s] ", head->key);
        PRINT_TREE(head->left);
        PRINT_TREE(head->right);
        return;
    }
}   //각종 출력 함수

int main() {
    OBST(N-1);

    PRINT(A, 'A');
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            printf("R[%d][%d] : %d\n", i, j, R[i][j]);
        }
    }
    printf("-------------------------\n");

    node* Tree = TREE(1,6);
    PRINT_TREE(Tree);

    return 0;
}