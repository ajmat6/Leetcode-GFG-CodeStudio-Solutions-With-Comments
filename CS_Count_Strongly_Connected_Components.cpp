#include<unordered_map>
#include<stack>
#include<list>
#include<vector>

void dfs(int node, unordered_map<int, bool>& isVisited, stack<int>& s, unordered_map<int, list<int>>& adj)
{
	isVisited[node] = true;

	for(auto i: adj[node])
	{
		if(!isVisited[i])
		{
			dfs(i, isVisited, s, adj);
		}
	}

	// Storing in stack for topo sort when all the adj nodes of a node are visited:
	s.push(node);
}

// DFS traversal for finding Strongly connected component:
void SCCdfs(int node, unordered_map<int, bool>& isVisited, unordered_map<int, list<int>>& transpose)
{
	isVisited[node] = true;

	for(auto i: transpose[node])
	{
		if(!isVisited[i])
		{
			SCCdfs(i, isVisited, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Create Adjacency list:
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// Topological sort using DFS:
	stack<int> s;
	unordered_map<int, bool> isVisited;
	for(int i=0; i<v; i++)
	{
		if(!isVisited[i])
		{
			dfs(i, isVisited, s, adj);
		}
	}

	// Transposing the graph(storing the reverse of the adj list in the graph):
	unordered_map<int, list<int>> transpose;
	for(int i=0; i<v; i++)
	{
		for(auto nbr: adj[i])
		{
			transpose[nbr].push_back(i);
		}
	}

	// DFS traversal using top sort and above transposed graph:
	int count = 0;
	unordered_map<int, bool> isVisited2;
	while(!s.empty())
	{
		int top = s.top();
		s.pop();

		// logic for counting strongly connected component:
		if(!isVisited2[top]) count++;

		// Visiting adjacent nodes of the top node:
		for(auto i: transpose[top])
		{
			if(!isVisited2[i])
			{
				SCCdfs(i, isVisited2, transpose);
			}
		}
	}

	return count;
}