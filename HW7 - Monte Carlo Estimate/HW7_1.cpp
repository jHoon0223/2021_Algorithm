#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 8
#define IterN 20

int column[N+1];
char *include[N+1];

bool promising(int a) {
    bool flag = true;

    int i = 1;
    while (i < a && flag) {
        if (column[a] == column[i] || abs(column[a]-column[i]) == a-i)
            flag = false;
        i++;
    }
    return flag;
}
int MCE(int a) {
    int i = 0, j;
    int m = 1;
    int mProd = 1;
    int totalNodes = 1;

    int promisingChild[N];
    int idx = 0;

    Sleep(1000);
    srand(time(NULL));

    while(m!=0 && i < a) {
        mProd = mProd * m;
        totalNodes += mProd*a;
        i++;

        m = 0;
        idx = 0;

        for (j = 1; j <= a; j++) {
            column[i] = j;

            if (promising(i)) {
                m++;
                promisingChild[idx] = m;
                idx++;
            }
        }
        if (m != 0) {
            j = rand()%a + 1;
            column[i] = j;
        }
    }
    return totalNodes;
}

int main() {
    int total = 0, tmp;

    printf(">> Requiring Nodes for N = 8 <<\n");
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