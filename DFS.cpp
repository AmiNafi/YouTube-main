
#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int clr[1000];
vector<int> adj[1000];
void dfs(int node)
{
    clr[node] = 1;
    cout << "current node = " << node << endl;
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbour = adj[node][i];
        if (clr[neighbour] == 1)
        {
            cout << "CYCLE!!!!!!!!!!!!!!!!!!" << endl;
        }
        if (not visited[neighbour])
        {
            dfs(neighbour);
        }
    }
    clr[node] = 2;
    cout << "back = " << node << endl;
}

int main()
{
    int total_nodes, total_edges;
    cin >> total_nodes >> total_edges;
    for (int i = 0, node1, node2; i < total_edges; i++)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }
    dfs(1);
    return 0;
}
