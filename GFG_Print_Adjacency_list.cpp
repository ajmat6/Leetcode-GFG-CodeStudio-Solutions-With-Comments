class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        for(int i=0; i<V; i++)
        {
            temp.push_back(i);
            for(int j=0; j<adj[i].size(); j++)
            {
                temp.push_back(adj[i][j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};