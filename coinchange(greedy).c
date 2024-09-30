#include <stdio.h>
int main() {
 int amount, n, i, j, coinCount = 0, temp;
 int coins[50];
 printf("Enter the total amount: ");
 scanf("%d", &amount);
 printf("Enter the number of coins: ");
 scanf("%d", &n);
 printf("Enter the denominations of coins:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &coins[i]);
 }
 for(i=0;i<n;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(coins[j]<coins[i])
 {
 temp = coins[j];
 coins[j] = coins[i];
 coins[i] = temp;
 }
 }
 }
 printf("Coins used: ");
 for (i = n - 1; i >= 0; i--) {
 while (amount >= coins[i]) {
 amount -= coins[i];
 coinCount++;
 printf("%d ", coins[i]);
 }
 }
 printf("\nTotal coins needed: %d\n", coinCount);
 return 0;
}