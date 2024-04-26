#include <stdio.h>
#include <stdbool.h>

#define INF 9999999
#define V 4

int G[V][V];

// Function to input the graph
void inputGraph() {
    printf("Enter the adjacency matrix (size %d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }
}

int main() {
    inputGraph();

    int no_edge = 0;
    bool selected[V];
    int parent[V];
    int minWeight, u, v;
    int totalWeight = 0;

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        selected[i] = false;
        parent[i] = -1;
    }

    selected[0] = true;

    // Print MST edges
    printf("Edges\tWeight\n");

    while (no_edge < V - 1) {
        minWeight = INF;
        u = v = -1;

        // the minimum weight edge
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (G[i][j] < minWeight) {
                            minWeight = G[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%c - %c\t%d\n", 'A' + u, 'A' + v, minWeight);
            selected[v] = true;
            parent[v] = u;
            //  weight of the current edge to totalWeight
            totalWeight += minWeight;
            no_edge++;
        }
    }

    // Print the MST
    printf("\nMinimum Spanning Tree:\n");
    for (int i = 1; i < V; i++) {
        printf("%c - %c\n", 'A' + parent[i], 'A' + i);
    }

    printf("\nTotal weight of the Minimum Spanning Tree: %d\n", totalWeight);

    return 0;
}
