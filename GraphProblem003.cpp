#include <iostream>
#include <queue>
using namespace std;

int main() {
    int graph[4][4] = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int n = 4;
    int start = 0;
    bool visited[4] = {false};
    queue<int> q;

    // Start BFS from the given node
    visited[start] = true;
    q.push(start);

    cout << "Shortest path from " << start << ": [";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node;
        bool first = true;

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }

        if (!q.empty()) cout << ", ";
    }

    cout << "]" << endl;
    return 0;
}
