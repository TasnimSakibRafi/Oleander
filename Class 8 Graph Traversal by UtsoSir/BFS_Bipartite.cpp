#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool BFS_Traverse(vector<vector<int>> graph,vector<bool> &visited, int source)
{
    queue<int>  queue_l;
    vector<int> connected;
    vector<int> color(graph.size(), -1);

    queue_l.push(source);
    visited[source] = true;
    color[source] = 1;

    while( !queue_l.empty() )
    {
        // popping current node from queue front
        int current = queue_l.front();
        queue_l.pop();
        connected.push_back(current);

        //traverse all the neighbors of current node
        for(int i=0; i<graph[current].size(); i++)
        {
            int neighbour = graph[current][i];
            if( !visited[neighbour] )
            {
                queue_l.push(neighbour);
                visited[neighbour] = true;
                color[neighbour] = 1 - color[current];
            }
            else
            {
                if( color[current] == color[neighbour] )
                {
                   return false;
                }
            }
        }
    }
    return true;

//    for(int i=0; i<connected.size(); i++)
//    {
//        cout<<connected[i]<<" ";
//    }
//    cout<<endl;

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

//    int source_vertex;
//    cout<<"Enter your source vertex for BFS traversal: ";
//    cin >> source_vertex;

    vector<bool> visited(graph.size(),false);
    int island = 0;
    bool is_bipartite = true;

    for(int i=0; i<V; i++)
    {
        if ( visited[i] == false )
        {
             island++;
             is_bipartite = BFS_Traverse(graph, visited, i);
             if( !is_bipartite ){
                break;
             }
        }
    }

    if( !is_bipartite )
    {
        cout<<" The graph is not bipartite"<<endl;
    }
    else
    {
        cout<<"The graph is bipartite"<<endl;
    }
    //cout<<"Total Island : "<<island<<endl;

}

