#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];   
int visited[MAX];    
int queue[MAX];
int front = 0, rear = 0;
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;    
}
void enqueue(int v) {
    queue[rear++] = v;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
void BFS(int start, int vertices) {
    visited[start] = 1;
    enqueue(start);
    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
int main() {
    int vertices, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    BFS(start, vertices);
    return 0;
}