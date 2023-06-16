// TC = O((E+V)logV) where V is no of vertices and E are no of Edges
// SC = O(E+V)

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacancy list:
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i=0; i<vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Make distance vector and initialize it with inifinity:
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++)
        dist[i] = INT_MAX;

    // Make a set to track the min distace element:
    set<pair<int, int>> s;

    // Source node distance and inserting it into the set:
    dist[source] = 0;
    s.insert(make_pair(0, source));

    while(!s.empty())
    {
        // Fetch top record from the set(min distance element from the set):
        auto top = *(s.begin());
        s.erase(s.begin()); // removing the min distance element from the set

        int element = top.second; // becoz we have to traverse the adjacent nodes of the element

        for(auto i: adj[element])
        {
            if(top.first + i.second < dist[i.first])
            {
                // if above condition satisfies check if any element with same node in the set exist:
                auto record = s.find(make_pair(dist[i.first], i.first));

                // if above record found, then:
                if(record != s.end())
                {
                    s.erase(record);
                }

                // Distance update:
                dist[i.first] = top.first + i.second;
                s.insert(make_pair(dist[i.first], i.first));
            }
        }
    }

    return dist;
}
