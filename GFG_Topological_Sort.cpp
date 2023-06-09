class Solution
{
	public:
	void TopoSortDFS(vector<int> adj[], unordered_map<int, bool>& isVisited, stack<int>& s, int node)
    {
        isVisited[node] = true;
    
        for(auto i: adj[node])
        {
            if(!isVisited[i])
            {
                TopoSortDFS(adj, isVisited, s, i);
            }
        }
    
        // Marking isDFSVisited false again when all of its adjacent are visited
        s.push(node);
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        unordered_map<int, bool> isVisited;
        vector<int> ans;
        stack<int> s;
    
        // Checking for each component of the graph
        for(int i=0; i<V; i++)
        {
            if(!isVisited[i])
            {
                TopoSortDFS(adj, isVisited, s, i);
            }
        }
    
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
	}
};