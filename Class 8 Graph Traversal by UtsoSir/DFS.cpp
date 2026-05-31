#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void DFS_Traverse(vector<vector<int>> graph,vector<bool> &visited, int source)
{
    stack<int>  queue_l;

    queue_l.push(source);
    visited[source] = true;


    while( !queue_l.empty() )
    {
        // popping current node from queue front
        int current = queue_l.top();
        queue_l.pop();
        cout<<current<<" ";

        //traverse all the neighbors of current node
        for(int i=0; i<graph[current].size(); i++)
        {
            int neighbour = graph[current][i];
            if( !visited[neighbour] )
            {
                queue_l.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

}

int main()
{
    int V,E;

    cout<<"Enter total Vertex: ";
    cin>>V;
    cout<<"Enter total edges: ";
    cin>>E;

    // graph declaration
    vector<vector<int>> graph(V);
     // Adding edge
    for(int i=1; i <= E; i++)
    {
        int x,y;
        cout<<"Enter edge "<<i<<":";
        cin>>x>>y;

        if( x<V && x>=0 && y>=0 && y<V )
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    cout<<"Graph Adjacency List is:"<<endl;
    // print the graph
    for(int i=0; i<V; i++)
    {
        cout<<i<<" : ";
        for(int j = 0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<"->";
        }
        cout<<endl;
    }

    int source_vertex;
    cout<<"Enter your source vertex for DFS traversal: ";
    cin >> source_vertex;

    vector<bool> visited(graph.size(),false);

    for(int i=0; i<V; i++)
    {
        if ( visited[i] == false )
        {
             DFS_Traverse(graph, visited, i);
        }
    }

}

