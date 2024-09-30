#include <stdio.h>
#include <limits.h>
#define V 5
int minKey(int key[], int mstSet[]) {
 int min = INT_MAX, min_index;
 int v;
 for(v = 0; v < V; v++) {
 if (mstSet[v] == 0 && key[v] < min) {
 min = key[v];
 min_index = v;
 }
 }
 return min_index;
}
void printMST(int parent[], int graph[V][V]) {
 int i;
 printf("Edge \tWeight\n");
 for (i = 1; i < V; i++) {
 printf("%d - %d \t%d \n", parent[i], i, graph[i]
[parent[i]]);
 }
}
void primMST(int graph[V][V]) {
 int i, v, count;    
 int parent[V];
 int key[V];
 int mstSet[V];
 for (i = 0; i < V; i++) {
 key[i] = INT_MAX;
 mstSet[i] = 0;
 }
 key[0] = 0;
 parent[0] = -1;
 for (count = 0; count < V - 1; count++) {
 int u = minKey(key, mstSet);
 mstSet[u] = 1;
 for (v = 0; v < V; v++) {
 if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <
key[v]) {
 parent[v] = u;
 key[v] = graph[u][v];
 }
 }
 }
 printMST(parent, graph);
}
int main() {
 int v, i, j;
 int graph[V][V];
 printf("Enter number of vertices: ");
 scanf("%d", &v);
 printf("Enter adjacency matrix:\n");
 for (i = 0; i < V; i++) {
 for (j = 0; j < V; j++) {
 scanf("%d", &graph[i][j]);
 }
 }
 primMST(graph);
 return 0;
}