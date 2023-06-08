void CreateAdjList(unordered_map<int, set<int>>& adjList, vector<vector<int>> &edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& isVisited, vector<int>& component, int node)
{
    isVisited[node] = true;
    component.push_back(node);


    for(auto i: adjList[node])
    {
        if(!isVisited[i])
        {
            // isVisited[i] = true;
            dfs(adjList, isVisited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> isVisited;

    // Create adjacency list:
    CreateAdjList(adjList, edges);

    // Traverse all components as graph can be disconnected:
    for(int i=0; i<V; i++)
    {
        if(!isVisited[i])
        {
            vector<int> component;
            dfs(adjList, isVisited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}