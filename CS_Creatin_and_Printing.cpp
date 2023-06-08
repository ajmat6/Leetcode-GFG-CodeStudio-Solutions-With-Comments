// TC = O(m*n)
// SC = O(m+n)

#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> temp[n]; // creating n vectors for each node
    vector<vector<int>> ans(n); // creating ans vector of size n

    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // As graph is directed so both vertex have an edge between them:
        temp[u].push_back(v);
        temp[v].push_back(u);
    }

    for(int i=0; i<n; i++)
    {
        ans[i].push_back(i);
        for(int j=0; j<temp[i].size(); j++)
        {
            ans[i].push_back(temp[i][j]);
        }
    }
    return ans;
}