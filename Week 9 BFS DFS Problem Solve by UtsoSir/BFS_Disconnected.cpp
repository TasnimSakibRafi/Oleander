#include<iostream>
#include<queue>
#include<vector>

using namespace std;







bool BFS_Help(vector<vector<int>> graph, vector<bool> &visited, int source_vertex)
{
    queue<int> bfs_queue;
    vector<int> parent(graph.size(),-1);
    vector<int> depth(graph.size(), 0);
    vector<int> color(graph.size(), -1);


    bfs_queue.push(source_vertex);
    visited[source_vertex] = true;
    color[source_vertex] = 0;

    while( !bfs_queue.empty() )
    {
        int current_node = bfs_queue.front();
        bfs_queue.pop();
        //cout<<current_node<<" ";

        //traverse all the adjacent node of current node
        for(int i=0; i < graph[current_node].size(); i++)
        {
            int neighbour_node = graph[current_node][i];
            if( !visited[neighbour_node] )
            {
                visited[neighbour_node] = true;
                bfs_queue.push(neighbour_node);
                parent[neighbour_node] = current_node;
                depth[neighbour_node] = depth[current_node] + 1;
                color[neighbour_node] = 1 - color[current_node];

            }
            else
                
            {
                if(color[current_node] == color[neighbour_node])
                {
                    return false;
                }
            }
        }
    }
    return true;
}










int main()
{
    int V, E;

    cout<<"Enter total vertex: ";
    cin>>V;

    cout<<"Enter total edges: ";
    cin>>E;

    // graph declaration
    vector<vector<int>> graph(V);

    // add edge
    for(int i=1; i<=E; i++)
    {
        int x, y;
        cout<<"Enter edge "<<i<<" : ";
        cin>>x>>y;

        if( x>=0 && x<V && y>=0 && y<V )
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    vector<bool> visited(V, false);

    bool bipartite_flag = true;

    for(int i=0; i<V; i++)
    {
        if( !visited[i] )
        {
            if( !BFS_Help(graph, visited, i) )
            {
                bipartite_flag = false;
                break;
            }
        }
    }
    if( bipartite_flag == false)
    {
        cout<<"The graph is not bipartite"<<endl;
    }
    else
    {
        cout<<"The graph is bipartite"<<endl;
    }
}

