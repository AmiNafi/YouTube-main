
#include <bits/stdc++.h>
using namespace std;
int visited[1000], dis[1000], parent[1000];
vector<int> adj[1000];
void bfs(int source)
{
    queue<int> list;
    list.push(source);
    visited[source] = 1;
    dis[source] = 0;
    while (not list.empty())
    {
        int top_node = list.front();
        for (int i = 0; i < adj[top_node].size(); i++)
        {
            int new_node = adj[top_node][i];
            if (not visited[new_node])
            {
                dis[new_node] = dis[top_node] + 1;
                visited[new_node] = 1;
                list.push(new_node);
                parent[new_node] = top_node;
            }
        }
        list.pop();
    }
}
int main()
{
    int total_nodes, total_edges;
    cin >> total_nodes >> total_edges;
    for (int i = 0, node1, node2; i < total_edges; i++)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    bfs(1);
    int current_node = 10;
    vector<int> path;
    while (current_node != 1)
    {
        path.push_back(current_node);
        current_node = parent[current_node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "Distance of node " << i << " = " << dis[i] << endl;
    }
    return 0;
}
