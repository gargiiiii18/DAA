#include <stdio.h>
#include <limits.h>
int matrixChainMultiplication(int p[], int n) {
 int i, l, j, k, q;    
 int m[50][50];
 for (i = 1; i < n; i++) {
 m[i][i] = 0;
 }
 for (l = 2; l < n; l++) {
 for (i = 1; i < n - l + 1; i++) {
 j = i + l - 1;
 m[i][j] = INT_MAX;
 for (k = i; k <= j - 1; k++) {
 q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] *p[j];
 if (q < m[i][j]) {
 m[i][j] = q;
 }
 }
 }
 }
 return m[1][n - 1];
}

int main() {
 int n, i, minMultiplications;
 int dimensions[50];
 printf("Enter the number of matrices: ");
 scanf("%d", &n);
 n+=1;
 printf("Enter the dimensions of matrices:\n");
 for (i = 0; i < n; i++) {
 printf("Dimension %d: ", i+1);
 scanf("%d", &dimensions[i]);
 }
 minMultiplications = matrixChainMultiplication(dimensions, n);
 printf("Minimum number of multiplications needed: %d\n", minMultiplications);
 return 0;
}