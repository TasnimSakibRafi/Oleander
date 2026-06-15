#include <iostream>
using namespace std;

int main()
{
    int V, E;
    int adjMatrix[100][100] = {0};

    cout << "Enter the Number of Vertices : ";
    cin >> V;
    cout << "Enter The Number Of Eadges : ";
    cin >> E;

    cout << "Enter The Eadges (u,v) : ";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "ADJ Matrix of the Graph :  " << endl;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}