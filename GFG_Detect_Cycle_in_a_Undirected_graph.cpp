// TC -> O(V+E)
// SC -> O(V)
class Solution {
  public:
    // To Detect cycle in the graph -> if a  node is already visited and it is not a parent.
    bool isBFSCyclic(vector<int> adj[], unordered_map<int, bool>& isVisited, int node, unordered_map<int, int>& parent)
    {
        queue<int> q;
        q.push(node);
        
        parent[node] = -1;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(int i=0; i<adj[front].size(); i++)
            {
                if(!isVisited[adj[front][i]])
                {
                    q.push(adj[front][i]);
                    isVisited[adj[front][i]] = true;
                    parent[adj[front][i]] = front; // Tracking parent
                }
                
                // Condition for the cycle in the graph
                else if(isVisited[adj[front][i]] && adj[front][i] != parent[front])
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // isVisited Mapping:
        unordered_map<int, bool> isVisited;
        
        // Parent Track:
        unordered_map<int, int> parent;
        
        // Handle disconnected graph:
        for(int i=0; i<V; i++)
        {
            if(!isVisited[i])
            {
                isVisited[i] = true;
                bool ans = isBFSCyclic(adj, isVisited, i, parent);
                if(ans) return true;
            }
        }
        
        return false;
    }
};