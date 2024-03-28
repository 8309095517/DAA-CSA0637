#include <stdio.h>
#include <stdbool.h>

#define V 5 

void hamiltonianCircuit(int graph[V][V]);
bool isSafe(int v, int graph[V][V], int path[], int pos);
bool hamiltonianCircuitUtil(int graph[V][V], int path[], int pos);


void printSolution(int path[]) {
    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}


bool isSafe(int v, int graph[V][V], int path[], int pos) {
    
    if (graph[path[pos - 1]][v] == 0)
        return false;
  
    
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
  
    return true;
}


bool hamiltonianCircuitUtil(int graph[V][V], int path[], int pos) {
    
    if (pos == V) {
        
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
  
   
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            
            if (hamiltonianCircuitUtil(graph, path, pos + 1))
                return true;
            
            path[pos] = -1;
        }
    }
  
    return false;
}


void hamiltonianCircuit(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
  
   
    path[0] = 0;
    if (!hamiltonianCircuitUtil(graph, path, 1)) {
        printf("Hamiltonian Circuit does not exist\n");
        return;
    }
  
    
    printSolution(path);
}


int main() {
    
    int graph[V][V] = { {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0} };
    hamiltonianCircuit(graph);
    return 0;
}
