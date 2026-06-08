#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    int V, E;

    cout<<"Enter total vertex: ";
    cin>>V;

    cout<<"Enter total edges: ";
    cin>>E;

   
    vector<vector<int>> graph(V);

 
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
    queue<int> bfs_queue;
    vector<int> parent(V,-1);
    vector<int> distance(V, -1);

    int source_vertex;
    cout<<"Enter source vertex : ";
    cin>>source_vertex;


    bfs_queue.push(source_vertex);
    visited[source_vertex] = true;
    distance[source_vertex] = 0;

    while( !bfs_queue.empty() )
    {
        int current_node = bfs_queue.front();
        bfs_queue.pop();
    




        
        for(int i=0; i < graph[current_node].size(); i++)
        {
            int neighbour_node = graph[current_node][i];
            if( !visited[neighbour_node] )
            {
                visited[neighbour_node] = true;
                bfs_queue.push(neighbour_node);
                parent[neighbour_node] = current_node;
                distance[neighbour_node] = distance[current_node] + 1;
            }
        }
    }





    

    for(int i=0; i<distance.size(); i++)
    {
        cout<<distance[i]<<" ";
    }




    

    stack<int> path;
    int destination_vertex;

    cout<<"Enter Destination Vertex: ";
    cin>>destination_vertex;

    int current_vertex = destination_vertex;

    path.push(destination_vertex);

    while(parent[current_vertex] != -1 )
    {
        current_vertex = parent[current_vertex];
        cout<<"Current Vertex: "<<current_vertex<<endl;
        path.push(current_vertex);
    };

    while(!path.empty())
    {
        cout<<path.top()<<"->";
        path.pop();
    }

}
