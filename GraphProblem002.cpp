#include <iostream>
using namespace std;

void dfs(int v, int graph[10][10], bool visited[], int n) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, n);
        }
    }
}

int main() {
    int graph[4][4] = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };

    int n = 4;
    bool visited[10] = {false};

    
    dfs(0, graph, visited, n);

    
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "The graph is connected";
    else
        cout << "The graph is not connected";

    return 0;
}
