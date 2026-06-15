#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value);
void addEdge(Node* graph[], int u, int v);
void display(Node* graph[], int vertices);

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    Node* graph[100] = {NULL};

    cout << "Enter edges (u,v): ";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    display(graph, vertices);

    return 0;
}

void addEdge(Node* graph[], int u, int v) {
    Node* nn = createNode(v);
    nn->next = graph[u];
    graph[u] = nn;
}

Node* createNode(int value) {
    Node* nn = new Node();
    nn->data = value;
    nn->next = NULL;
    return nn;
}

void display(Node* graph[], int vertices) {
    cout << "Adjacency list of the graph is:\n";

    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        Node* temp = graph[i];

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
