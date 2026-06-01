#include<iostream>
using namespace std;

int main() {

    int V, E;
    //scanf("%d %d", &V, &E);
    cout<<"Enter your total vertices: ";
    cin>>V;
    cout<<"Enter your total edges: ";
    cin>>E;

    int Graph[V+1][V+1];
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            Graph[i][j] = 0;
        }

    }
    for(int i=0;i<E;i++) {
        // edge start and end vertex
        int u, v;
        cout<<"Enter edge "<<i+1<<" ";
        //scanf("%d %d", &u, &v);
        cin>>u>>v;
        /// assume an undirected edge
        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
