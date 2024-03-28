#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to perform Floyd's Algorithm
void floydAlgorithm(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix with graph weights
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update distance matrix by considering all intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between all pairs of vertices
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { {0, 5, INT_MAX, 10},
                        {INT_MAX, 0, 3, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 1},
                        {INT_MAX, INT_MAX, INT_MAX, 0} };

    floydAlgorithm(graph);

    return 0;
}
