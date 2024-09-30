#include <stdio.h>
#include <limits.h>
int min(int a, int b) {
 return (a < b) ? a : b;
}

int minCoins(int coins[], int n, int amount) {
 int dp[50][50];
 int i, j;
 for (i = 0; i <= n; i++) {
 for (j = 0; j <= amount; j++) {
 if (j == 0) {
 dp[i][j] = 0;
 } else {
 dp[i][j] = INT_MAX;
 }
 }
 }
 for (i = 1; i <= n; i++) {
 for (j = 1; j <= amount; j++) {
 if (coins[i - 1] <= j) {
 dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
 } 
 else {
 dp[i][j] = dp[i - 1][j];
 }
 }
 }
 return dp[n][amount];
}

int main() {
 int amount, n, i, result;
  int coins[50];
 printf("Enter the total amount: ");
 scanf("%d", &amount);
 printf("Enter the number of coins: ");
 scanf("%d", &n);

 printf("Enter the denominations of coins:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &coins[i]);
 }
 result = minCoins(coins, n, amount);
 printf("Minimum number of coins required: %d\n", result);
 return 0;
}