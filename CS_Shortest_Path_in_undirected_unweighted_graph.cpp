#include<unordered_map>
#include<queue>
#include<vector>
#include<list>

// TC = O(v+e)
// SC = O(v+e)

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

    // Creating adjacency list:
	unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
		adj[v].push_back(u);
    }

	// BFS Traversal:
	unordered_map<int, bool> isVisited;
	unordered_map<int, int> parent;

	queue<int> q;
	q.push(s); // pushing source node into the queue
	parent[s] = -1;
	isVisited[s] = true;


	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(auto i: adj[front])
		{
			if(!isVisited[i])
			{
				isVisited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}
	
	// Till here you will get the parent map, so track to the parent:
	vector<int> ans;
	int currNode = t;
	ans.push_back(currNode);

	while(currNode != s)
	{
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
