#include<unordered_map>
#include<list>

void CreateAdjList(vector<vector<int>>& edges, unordered_map<int, list<int>>& adj)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool isCyclicDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited, int node, int parent)
{
    isVisited[node] = true;

    for(auto i: adj[node])
    {
        // Condition of cycle detection
        if(isVisited[i] && i != parent) return true;

        else if(!isVisited[i])
        {
            bool cycle = isCyclicDFS(adj, isVisited, i, node);
            if(cycle) return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;

    //Create adjacancy list:
    CreateAdjList(edges, adj);

    // Checking for each component of the graph
    for(int i=0; i<n; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            bool ans = isCyclicDFS(adj, isVisited, i, -1);
            if(ans) return "Yes";
        }
    }

    return "No";
}
