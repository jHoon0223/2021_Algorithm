#include <stdio.h>
//key1,key2...keyn
typedef int index;//
const float p[7] = { NULL, 0.05, 0.15, 0.05, 0.35, 0.5, 0.35};
float sum(index begin, index end)
{
float sum_total = 0;
for (int i = begin; i <= end; i++)
{
sum_total += p[i];
}
return sum_total;
}
//optimal search tree
void optsearchtree(index n,index **R)
{
index i, j, k, diagonal;
float **A = new float*[n + 2];
float min;
for (int s = 0; s < n + 2; s++)
A[s] = new float[n + 1];
// 계산 안하는 구간 처리
for (i = 1; i <= n; i++)
{
A[i][i - 1] = 0;
A[i][i] = p[i];
A[0][i - 1] = NULL;
R[i][i] = i;
R[i][i - 1] = 0;
R[0][i - 1] = NULL;
}
A[0][n] = NULL;
A[n + 1][n] = 0;
R[0][n] = NULL;
R[n + 1][n] = 0;
for (diagonal = 1; diagonal <= n-1; diagonal++)
{
for (i = 1; i <= n - diagonal; i++)
{
j = i + diagonal;
min = A[i][i-1] + A[i + 1][j] + sum(i,j);
for (k = i; k <= j; k++)
{
if (min >= A[i][k - 1] + A[k + 1][j] + sum(i, j))
{
min = A[i][k-1] + A[k + 1][j] + sum(i, j);
R[i][j] = k;
}
}
A[i][j] = min;
}
}
for (index i = 1; i <= n; i++)
{
for (index j = i; j <= n; j++)
{
printf("A[%d][%d] ::%.2f", i, j, A[i][j]);
printf("\n");
}
}
for (int s = 0; s < n + 2; s++)
delete[]A[s];
}
int main() {
int n = sizeof(p) / sizeof(float)-1;
//R[i][j] i~j
index **R=new index *[n + 2];
for (int i = 0; i < n + 2; i++)
{
R[i] = new index[n + 1];
}
optsearchtree(n,R);
for (int i = 1; i <= n; i++)
{
for (int j = i; j <= n; j++)
{
printf("R[%d][%d] ::%d", i, j, R[i]
[j]);
printf("\n");
}
}
for (int i = 0; i < n + 2; i++)
delete[] R[i];
return 0;
}