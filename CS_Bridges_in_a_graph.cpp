#include<unordered_map>
#include<vector>
#include<list>

// TC = O(N+E)
// SC = O(N+E)

void dfs(int node, int& parent, int& timer, vector<int>& disc, vector<int>& low, vector<vector<int>>& ans, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited)
{
    // Marking visited:
    isVisited[node] = true;

    // Updating disc and low time in beginning equal to the timer:
    disc[node] = low[node] = timer++;

    for(auto neigbour: adj[node])
    {
        // if adjacent node of a node is its parent -> ignore:
        if(neigbour == parent) continue;

        // Checking for the Back Edge:

        if(!isVisited[neigbour])
        {
            // Recursive call for the adjacent nodes:
            dfs(neigbour, node, timer, disc, low, ans, adj, isVisited);

            // updating the low of the parent after the recursion:
            low[node] = min(low[node], low[neigbour]);

            // check for bridge edge:
            if(low[neigbour] > disc[node])
            {
                // storing the nodes pair in the ans vector:
                ans.push_back({node, neigbour});
            }
        }

        // Back Edge Case (node that is already visited and also is not parent):
        else
        {
            low[node] = min(low[node], disc[neigbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Create adj list:
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initializing the bridge algo DS:
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> isVisited;

    for(int i=0; i<v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // to store ans:
    vector<vector<int>> ans;

    // Applying DFS for Traversal:
    for(int i=0; i<v; i++)
    {
        if(!isVisited[i])
        {
            dfs(i, parent, timer, disc, low, ans, adj, isVisited);
        }
    }

    return ans;
}