#include<iostream>
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
            //graph[y].push_back(x);
        }
    }

    stack<int> st;
    vector<bool> visited(V, false);

    int source_vertex;
    cout<<"Enter source vertex : ";
    cin>>source_vertex;

    st.push(source_vertex);
    visited[source_vertex] = true;

    while( !st.empty() )
    {
        int current_node = st.top();
        st.pop();
        cout<<current_node<<" ";

        for(int i=0; i<graph[current_node].size(); i++)
        {
            int neighbour_node = graph[current_node][i];
            if( !visited[neighbour_node] )
            {
                visited[neighbour_node] = true;
                st.push(neighbour_node);
            }
        }
    }

}
