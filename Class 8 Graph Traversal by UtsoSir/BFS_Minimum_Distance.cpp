#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void BFS_Traverse(vector<vector<int>> graph,vector<bool> &visited, int source, int destination)
{
    queue<int>  queue_l;
    vector<int> connected;
    vector<int> distance(graph.size(), -1);
    vector<int> parent(graph.size(), -1);

    queue_l.push(source);
    visited[source] = true;
    distance[source] = 0;

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
                distance[neighbour] =  distance[current] + 1;
                parent[neighbour] = current;
            }
            else
            {
                if(parent[current] != neighbour)
                {
                    cout<<"The graph contains a cycle"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"The graph does not contain a cycle"<<endl;

//    for(int i=0; i<connected.size(); i++)
//    {
//        cout<<connected[i]<<" ";
//    }
//    cout<<endl;

// printing distance from source

    for(int i=0; i<distance.size(); i++)
    {
        cout<<distance[i]<<" ";
    }
    cout<<endl;

    stack<int> st;
    st.push(destination);

    int cur = destination;
    while(parent[cur] != -1)
    {
        st.push(parent[cur]);
        cur = parent[cur];
    }

    cout<<"Shortest path between "<<source<<" and "<<destination<<" is : ";
    while( !st.empty())
    {
        int temp = st.top();
        st.pop();
        cout<<temp<<" -> ";
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
    cout<<"Enter your source vertex for BFS traversal: ";
    cin >> source_vertex;
    int destination_vertex;
    cout<<"Enter your destination vertex: ";
    cin >> destination_vertex;

    vector<bool> visited(graph.size(),false);
    BFS_Traverse(graph, visited, source_vertex, destination_vertex);


}
