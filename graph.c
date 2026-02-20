#include <stdio.h>
#include <limits.h>

int main() {
    int n, e, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter u v weight: ");
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // undirected graph
    }

    printf("\nWeighted Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int src;
    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        // Relax adjacent vertices
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                graph[minIndex][i] != 0 &&
                dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][i] < dist[i]) {

                dist[i] = dist[minIndex] + graph[minIndex][i];
            }
        }
    }

    // Output result
    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }

    return 0;
}
