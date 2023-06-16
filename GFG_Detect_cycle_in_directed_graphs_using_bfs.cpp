// TC = O(v+e)
// SC = O(v+e)
class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // Find indegree of all elements:
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto j: adj[i]) indegree[j]++;
        }
    
        // Push 0 indegree elements into the queue:
        queue<int> q;
        for(int i=0; i<V; i++)
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
        
        if(ans.size() != V) return true;
        else return false;
    }
};