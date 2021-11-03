#include <stdio.h>
#include <stdbool.h>

#define N 13
//Edge의 개수

int set[11];
//노드가 연결됐는지 판단. 1~10까지 사용하기 위해 크기를 11로 잡음

struct HEAP {
    int from;
    int to;
    int value;
};
//출발 Vertex와 도착 Vertex, Weight를 저장하는 Heap구조체

int getParent(int index) {
    if (set[index] == index) return index;
    return getParent(set[index]);
}   //부모 Vertex return. 없으면 자기자신 return.
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a<b) set[b] = a;
    else set[a] = b;
}   //두 Vertex를 작은값을 기준으로 연결
bool isCycle(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}   //순환 사이클이 존재하면 true, 아니면 false return

int main() {
        printf(">> Kruskal's Algorithm <<\n");
    printf("-------------------------\n");

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
    //정렬된 노드 오름차순으로 Heap 구조체에 저장

    printf("Sorted Edges >> \n"); 
    for (int i = 0; i < 13; i++)
        printf("(v%d, v%d) %d\n", H[i].from, H[i].to, H[i].value);
    printf("-------------------------\n");
    //오름차순 정렬된 노드 출력
    
    for (int i = 1; i < 10; i++) set[i] = i;
    //각 노드는 부모는 자기자신으로 초기화

    int total = 0, index = 0;
    struct HEAP MST[9];
    for (int i = 0; i < N; i++) {
        if (!isCycle(H[i].from, H[i].to)) {
            total += H[i].value;
            MST[index] = H[i];
            index++;
            unionParent(H[i].from, H[i].to);
        }   //순환 사이클이 존재하지 않으면, MST 구조체배열에 저장 후, total에 더함
    }

    printf("Minimum Spanning Tree >> \n"); 
    for (int i = 0; i < 9; i++)
        printf("(v%d, v%d) %d\n", MST[i].from, MST[i].to, MST[i].value);
    printf("-------------------------\n");

    printf("Minimum Distance >> "); 
    printf("%d\n", total);
    //Minimum Spanning Tree와 최소 비용 출력

    return 0;
}