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
    int queue[100];
    int front = 0, rear = -1;

    visited[start] = 1;
    rear++;
    queue[rear] = start;

    cout << "BFS Traversal: ";
    while (front <= rear) {
        int node = queue[front];
        front++;

        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjmatrix[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }

    cout << endl;
    return 0;
}
