#include <stdio.h>
#include <string.h>
void computeLPSArray(char* pattern, int M, int lps[]) {
 int len = 0;
 int i = 1;
 lps[0] = 0;
 while (i < M) {
 if (pattern[i] == pattern[len]) {
 len++;
 lps[i] = len;
 i++;
 } else {
 if (len != 0) {
 len = lps[len - 1];
 } else {
 lps[i] = 0;
 i++;
 }
 }
 }
}
void KMPSearch(char* pattern, char* text) {
 int M = strlen(pattern);
 int N = strlen(text);
 int found=0;
 int lps[50];
 int i = 0;
 int j = 0;
 computeLPSArray(pattern, M, lps);
 while (i < N) {
 if (pattern[j] == text[i]) {
 j++;
 i++;
 }
 if (j == M) {
 found=1;
 printf("Pattern found at index %d\n", i - j);
 j = lps[j - 1];
 } else if (i < N && pattern[j] != text[i]) {
 if (j != 0) {
 j = lps[j - 1];
 } else {
 i++;
 }
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
 KMPSearch(pattern, text);
 return 0;
}