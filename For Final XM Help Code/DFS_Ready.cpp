#include <iostream>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    int adjmatrix[100][100] = {0};

    cout << "Enter edges (u,v): ";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjmatrix[u][v] = 1;
        adjmatrix[v][u] = 1;
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    int visited[100] = {0};
    int stack[100];
    int top = -1;

    visited[start] = 1;
    top++;
    stack[top] = start;

    cout << "DFS Traversal: ";
    while (top != -1) {
        int node = stack[top];
        top--;

        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjmatrix[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                top++;
                stack[top] = i;
            }
        }
    }

    cout << endl;
    return 0;
}
