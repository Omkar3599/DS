
#include <stdio.h>

void createDirectedMatrix(int n, int adj[n][n]) {
    int src, dest;
    printf("Enter edges (source and destination) (-1 -1 to stop):\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        adj[src][dest] = 1;
    }
}

void createUndirectedMatrix(int n, int adj[n][n]) {
    int src, dest;
    printf("Enter edges (source and destination) (-1 -1 to stop):\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }
}

void displayMatrix(int n, int adj[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    int choice;
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);
    if (choice == 1) createDirectedMatrix(n, adjMatrix);
    else createUndirectedMatrix(n, adjMatrix);

    printf("Adjacency Matrix:\n");
    displayMatrix(n, adjMatrix);
    return 0;
}
