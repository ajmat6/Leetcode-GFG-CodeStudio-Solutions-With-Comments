#include<unordered_map>
#include<list>

// TC = O(N+E)
// SC = O(N+E)

void CreateAdjList(vector<pair< int, int >> & edges, unordered_map<int, list<int>>& adj)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }
}

bool isCyclicDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& isVisited, unordered_map<int, bool>& isDFSVisited, int node)
{
    isVisited[node] = true;
    isDFSVisited[node] = true;

    for(auto i: adj[node])
    {
        // Condition of cycle detection
        if(isVisited[i] && isDFSVisited[i]) return true;

        else if(!isVisited[i])
        {
            bool cycle = isCyclicDFS(adj, isVisited, isDFSVisited, i);
            if(cycle) return true;
        }
    }

    // Marking isDFSVisited false again when all of its adjacent are visited
    isDFSVisited[node] = false;
    
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> isVisited;
    unordered_map<int, bool> isDFSVisited;

    //Create adjacancy list:
    CreateAdjList(edges, adj);

    // Checking for each component of the graph
    for(int i=0; i<n; i++)
    {
        if(!isVisited[i])
        {
            bool ans = isCyclicDFS(adj, isVisited, isDFSVisited, i);
            if(ans) return true;
        }
    }

    return false;
}