#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<utility> //headerfile for pair
using namespace std;

// TC = O(N+E)
// SC = O(N+E)

void dfs(int node, int& parent, int& timer, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& isVisited, unordered_map<int, list<int>>& adj, vector<int>& ans)
{
    isVisited[node] = true;
    disc[node] = low[node] = timer++;

    // counting child of the node:
    int child = 0;

    for(auto neighbour: adj[node])
    {
        // if adjacent node of a node is its parent -> ignore:
        if(neighbour == parent) continue;

        if(!isVisited[neighbour])
        {
            dfs(neighbour, node, timer, disc, low, isVisited, adj, ans);

            // updating the low of the parent after the recursion:
            low[node] = min(low[node], low[neighbour]);

            // Check for articulation point:
            if(low[neighbour] >= disc[node] && parent != -1)
            {
                // Marking node as articulation point:
                ans[node] = 1;
            }

            // child increament:
            child++;
        }

        // Back Edge:
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    // check for the parent = -1 case:
    if(parent == -1 && child > 1)
    {
        ans[node] = 1;
    }
}

int main()
{
    // Making of the question:
    int nodes = 5;
    int edge = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({0, 4});

    // Create Adjacancy list:
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DS for the Articulation points algo(Tarjans algo):
    int timer = 0;
    int parent = -1;
    vector<int> disc(nodes);
    vector<int> low(nodes);
    unordered_map<int, bool> isVisited;

    // Initializing the DS:
    for(int i=0; i<nodes; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // ans store vector:
    vector<int> ans(nodes, 0);

    // DFS Traversal:
    for(int i=0; i<nodes; i++)
    {
        if(!isVisited[i])
        {
            dfs(i, parent, timer, disc, low, isVisited, adj, ans);
        }
    }
    
    // Print Articulation Points:
    cout << "Artculation Points are: " << endl;
    for(int i=0; i<nodes; i++)
    {
        if(ans[i] != 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}