#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>

void CreateAdjList(unordered_map<int, set<int>>& adjList, vector<pair<int, int>> edges)
{
    for(int i=0; edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> adjList, unordered_map<int, bool>& isVisited, vector<int>& ans, int node)
{
    queue<int> q;
    q.push(node);
    isVisited[node] = true;

    while(!q.empty())
    {
        int frontNode = q.front(); // 1st step -> storing the front element of the queue
        q.pop(); // 2nd step -> pop from the queue

        ans.push_back(frontNode); // 3rd step -> store in the ans vector

        for(auto i: adjList[frontNode]) // 4th step -> traverse all neighbours of the frontnode
        {
            if(!isVisited[i])
            {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> isVisited;

    // Create adjacency list:
    CreateAdjList(adjList, edges);

    // Traverse all components as graph can be disconnected:
    for(int i=0; i<vertex; i++)
    {
        if(!isVisited[i])
        {
            bfs(adjList, isVisited, ans, i);
        }
    }

    return ans;
}