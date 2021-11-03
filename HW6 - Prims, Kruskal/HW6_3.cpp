#include <stdio.h>
#include <stdbool.h>

#define N 13
//Edge�� ����

int set[11];
//��尡 ����ƴ��� �Ǵ�. 1~10���� ����ϱ� ���� ũ�⸦ 11�� ����

struct HEAP {
    int from;
    int to;
    int value;
};
//��� Vertex�� ���� Vertex, Weight�� �����ϴ� Heap����ü

int getParent(int index) {
    if (set[index] == index) return index;
    return getParent(set[index]);
}   //�θ� Vertex return. ������ �ڱ��ڽ� return.
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a<b) set[b] = a;
    else set[a] = b;
}   //�� Vertex�� �������� �������� ����
bool isCycle(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}   //��ȯ ����Ŭ�� �����ϸ� true, �ƴϸ� false return

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
    //���ĵ� ��� ������������ Heap ����ü�� ����

    printf("Sorted Edges >> \n"); 
    for (int i = 0; i < 13; i++)
        printf("(v%d, v%d) %d\n", H[i].from, H[i].to, H[i].value);
    printf("-------------------------\n");
    //�������� ���ĵ� ��� ���
    
    for (int i = 1; i < 10; i++) set[i] = i;
    //�� ���� �θ�� �ڱ��ڽ����� �ʱ�ȭ

    int total = 0, index = 0;
    struct HEAP MST[9];
    for (int i = 0; i < N; i++) {
        if (!isCycle(H[i].from, H[i].to)) {
            total += H[i].value;
            MST[index] = H[i];
            index++;
            unionParent(H[i].from, H[i].to);
        }   //��ȯ ����Ŭ�� �������� ������, MST ����ü�迭�� ���� ��, total�� ����
    }

    printf("Minimum Spanning Tree >> \n"); 
    for (int i = 0; i < 9; i++)
        printf("(v%d, v%d) %d\n", MST[i].from, MST[i].to, MST[i].value);
    printf("-------------------------\n");

    printf("Minimum Distance >> "); 
    printf("%d\n", total);
    //Minimum Spanning Tree�� �ּ� ��� ���

    return 0;
}