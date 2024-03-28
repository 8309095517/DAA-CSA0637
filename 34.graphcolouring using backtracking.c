#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices

// Function prototypes
void printSolution(int color[]);
bool isSafe(int v, bool graph[V][V], int color[], int c);
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v);

// Function to print the solution (coloring of vertices)
void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

// Function to check if it's safe to color the vertex with the given color
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Recursive utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are colored
    if (v == V)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if the color c is valid for vertex v
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recur to color the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If coloring vertex v with color c doesn't lead to a solution, backtrack and try another color
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Main function to solve the graph coloring problem
void graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive utility function to solve the problem
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return;
    }

    // Print the solution
    printSolution(color);
}

// Main driver code
int main() {
    // Example graph represented as an adjacency matrix
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3;  // Number of colors
    graphColoring(graph, m);
    return 0;
}
