#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int V, E;
    cout<<"Enter your total vertices: ";
    cin>>V;
    cout<<"Enter your total edges: ";
    cin>>E;

    vector<int> Graph[V+1];

    for(int i=0; i<E; i++)
    {
        int u, v;
        cout<<"Enter edge "<<i+1<<" ";
        //scanf("%d %d", &u, &v);
        cin>>u>>v;
        /// assume an undirected edge
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for(int i=1; i<=V; i++)
    {
        cout<<i<<" -> ";
        for(auto it:Graph[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
