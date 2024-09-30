#include <stdio.h>
#include <string.h>
void search(char* pattern, char* text) {
 int M = strlen(pattern);
 int N = strlen(text);
 int i, j;
 int found=0;
 for (i = 0; i <= N - M; i++) {

 for (j = 0; j < M; j++) {
 if (text[i + j] != pattern[j])
 break;
 }
 if (j == M)
 {
 printf("Pattern found at index %d\n", i);
 found=1;
 }
 }
 if(!found)
 {
 printf("Pattern not found\n");
 }
}
int main() {
 char text[100], pattern[100];
 printf("Enter the text: ");
 scanf("%s", text);
 printf("Enter the pattern: ");
 scanf("%s", pattern);
 search(pattern, text);
 return 0;
}