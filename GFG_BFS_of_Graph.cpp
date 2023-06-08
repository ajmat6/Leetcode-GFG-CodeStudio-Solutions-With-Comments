void bfs(vector<int> adj[], unordered_map<int, bool>& isVisited, vector<int>& ans, int node)
{
    queue<int> q;
    q.push(node);
    isVisited[node] = true;

    while(!q.empty())
    {
        int frontNode = q.front(); // 1st step -> storing the front element of the queue
        q.pop(); // 2nd step -> pop from the queue

        ans.push_back(frontNode); // 3rd step -> store in the ans vector

        for(auto i: adj[frontNode]) // 4th step -> traverse all neighbours of the frontnode
        {
            if(!isVisited[i])
            {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
}

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int, bool> isVisited;
        
        bfs(adj, isVisited, ans, 0);
        
        return ans;
    }
};