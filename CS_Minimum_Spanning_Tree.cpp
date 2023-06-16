#include<algorithm>
#include<vector>

// TC = O(mlogm) where m are no of edges
// SC = O(n) where n are no of nodes

// 2d vector of nodes and weight sort function:
bool cmp(vector<int>& a, vector<int>& b)
{
  return a[2] < b[2];
}

// Initializing disconnected graph components:
void makeset(vector<int>& parent, vector<int>& rank, int n)
{
  for(int i=0; i<n; i++)
  {
    // Initializing each element parent of itself(disjoin set):
    parent[i] = i;

    // Initializing each element rank as 0 in beginning:
    rank[i] = 0;
  }
}

// Find Parent function of disjoint set:
int findParent(vector<int>& parent, int node)
{
  // finding parent through path compression:
  
  // Base caseas (as when you were finding 7 node parent):
  if(parent[node] == node)
  {
    return node;
  }

  // setting up node parent its original parent by path compression so that next time it will not take much time
  parent[node] = findParent(parent, parent[node]);

  // return node parent
  return parent[node];
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank)
{
  // step-1 -> find parent of u and v:
  int parentU = findParent(parent, u);
  int parentV = findParent(parent, v);

  // step-2 -> check for the rank of the parents:

  // if ranks are not equal:
  if(rank[u] < rank[v])
  {
    parent[u] = v;
  }

  else if(rank[v] < rank[u])
  {
    parent[v] = u;
  }

  // if ranks are equal:
  else
  {
    parent[v] = u;
    rank[u]++;
  }

}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  // sorting the 2d vector on the basis of weights:
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeset(parent, rank, n);

  // kruskal's algo part:

  int minWeightAns = 0;

  // Traversing through the vector for kruskal's algo:
  for(int i=0; i<edges.size(); i++)
  {
    // find parents of nodes:
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int weight = edges[i][2];

    // if parents are not same -> merge/union and store min weight:
    if(u != v)
    {
      minWeightAns += weight;
      unionSet(u, v, parent, rank);
    }
  }

  return minWeightAns;
}