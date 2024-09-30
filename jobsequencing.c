#include <stdio.h>
#define MAX_JOBS 100
void swap(int *x, int *y) {
 int temp = *x;
 *x = *y;
 *y = temp;
}
void sortJobs(int id[], int deadline[], int profit[], int n) {
    int i, j, min_index;
 for (i = 0; i < n; i++) {
 min_index = i;
 for (j = i+1; j < n; j++) {
 if (profit[j] > profit[min_index]) {
 min_index = j;
 }
 }
 swap(&id[min_index], &id[i]);
 swap(&deadline[min_index], &deadline[i]);
 swap(&profit[min_index], &profit[i]);
 }
}
void jobSequencing(int id[], int deadline[], int profit[], int n)
{
    int i, j;
 int total_profit = 0;
 int slot[MAX_JOBS] = {0};
 for (i = 0; i < n; i++) {
 for (j = deadline[i] - 1; j >= 0; j--) {
 if (slot[j] == 0) {
 total_profit+=profit[i];
 slot[j] = id[i];
 break;
 }
 }
 }
 printf("Job Sequence with maximum profit:\n");
 for (i = 0; i < MAX_JOBS; i++) {
 if (slot[i]!=0) {
 printf("Slot %d ->Job %d\n",i+1, slot[i]);
 }
 }
 printf("\n");
 printf("Total profit: %d\n", total_profit);
 for(i=0;i<n;i++)
 {
 printf("%d ",profit[i]);
 }
}
int main() {
 int n, i;
 int id[MAX_JOBS], deadline[MAX_JOBS], profit[MAX_JOBS];
 printf("Enter the number of jobs: ");
 scanf("%d", &n);
 for (i = 0; i < n; i++) {
 printf("Enter deadline for job %d: ", i + 1);
 scanf("%d", &deadline[i]);
 id[i]=i+1;
 }
 for (i = 0; i < n; i++) {
 printf("Enter profit for job %d: ", i + 1);
 scanf("%d", &profit[i]);
 }
 sortJobs(id, deadline, profit, n);
 jobSequencing(id, deadline, profit, n);
 return 0;
}