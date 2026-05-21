#include <iostream>
using namespace std;

bool isBipartite(int **graph, int n) {
    int *color = new int[n];
    for (int i = 0; i < n; i++)
        color[i] = -1; 

    
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            int *queue = new int[n];
            int front = 0, rear = 0;

            color[start] = 0;
            queue[rear++] = start;

            while (front < rear) {
                int u = queue[front++];

                for (int v = 0; v < n; v++) {
                    if (graph[u][v] == 1) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            queue[rear++] = v;
                        } else if (color[v] == color[u]) {
                            delete[] queue;
                            delete[] color;
                            return false;
                        }
                    }
                }
            }
            delete[] queue;
        }
    }

    delete[] color;
    return true;
}




int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int **graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    if (isBipartite(graph, n)){
        cout << "The graph is bipartite";
    }
    else {
        cout << "The graph is not bipartite";
    }

    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}
