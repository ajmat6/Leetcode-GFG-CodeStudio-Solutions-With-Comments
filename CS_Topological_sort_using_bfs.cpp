#include <bits/stdc++.h> 

// TC = O(v+e)
// SC = O(v+e)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;

    // Creating adjacency list:
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Find indegree of all elements:
    vector<int> indegree(v, 0);
    for(auto i: adj)
    {
        for(auto j: i.second) indegree[j]++;
    }

    // Push 0 indegree elements into the queue:
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    // Do BFS:
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store:
        ans.push_back(front);

        // Decrease the indegree of the front element's adjacent elements and push them into queue if their indegree has become zero
        for(auto i: adj[front])
        {
            indegree[i]--;
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return ans;
}