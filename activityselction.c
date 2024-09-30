#include <stdio.h>
#include <stdlib.h>
void selectionSort(int a[], int b[], int c[], int n)
{
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++)
    {
	min_index = i;
	for (j = i + 1; j < n; j++)
	{
	    if (a[j] < a[min_index])
	    {
		min_index = j;
	    }
	}
	// Swap elements in all arrays
	temp = a[min_index];
	a[min_index] = a[i];
	a[i] = temp;
	temp = b[min_index];
	b[min_index] = b[i];
	b[i] = temp;
	temp = c[min_index];
	c[min_index] = c[i];
	c[i] = temp;
    }
}
int main()
{
    int n, start[50], end[50], name[50], i, j, count = 1;
    clrscr();
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
	printf("Enter start and finish time for activity %d: ", i + 1);
	scanf("%d %d", &start[i], &end[i]);
	name[i] = i + 1;
    }
    selectionSort(end, start, name, n);
    i = 0;
    printf("Activities that can be performed: Activity %d",
	   name[0]);
    for (j = 1; j < n; j++)
    {
	if (start[j] >= end[i])
	{
	    printf(" Activity %d", name[j]);
	    i = j;
	}
    }
    getch();
    return 0;
}
