#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create Ajacancy list:
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Create Key, mst and parent vectors:
    vector<int> key(n+1); // n+1 as we referencing index as node here and here nodes start from 1 index
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    // Initializing above all vector:
    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // Prim's algo start:

    // start from 1 node as source node and update its key, parent and mst vector:
    key[1] = 0;
    parent[1] = -1;

    // below for loop will n-1 times for the no of edges (n-1) in the spanning tree
    for(int i=1; i<n; i++)
    {
        // find min element index:
        int mini = INT_MAX;
        int u;

        // this for loop will make TC = O(n^2). Implement it using priority queue to make it O(nlogn)
        for(int j=1; j<=n; j++)
        {
            if(mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }

        // marking min element index as true in mst:
        mst[u] = true;

        // Cheking for the adjacent nodes of the min element and updating their key and parent vectors:
        for(auto i: adj[u])
        {
            if(mst[i.first] == false && i.second < key[i.first])
            {
                key[i.first] = i.second;
                parent[i.first] = u;
            }
        }
    }

    // Till here your parent vector is formed, create ans from it:
    vector<pair<pair<int, int>, int>> result;

    // Traversing thorugh the parent loop to construct min MST:
    // As here our nodes start from 1, we cannot start loop from 0, but also 1 node has parent -1 so we have to start loop from 2:
    for(int i=2; i<parent.size(); i++)
    {
        result.push_back({{i, parent[i]}, key[i]});
    }

    return result;
}
