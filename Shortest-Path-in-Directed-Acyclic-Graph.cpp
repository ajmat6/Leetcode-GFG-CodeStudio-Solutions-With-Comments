#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

class Graph
{
    public:
        unordered_map<int, list<pair<int, int>>> adj;

        // Creating edges between the nodes:
        void addEdge(int u, int v, int weight)
        {
            pair<int, int> p = {v, weight};
            adj[u].push_back(p);
        }

        // Printing the adjacency list:
        void printAdj()
        {
            for(auto i: adj)
            {
                cout << i.first << " -> ";
                for(auto j: i.second)
                {
                    cout << "(" <<  j.first << ", " << j.second << "), ";
                }
                cout << endl;
            }
        }

        // Procedure for Topological sort using dfs:
        void dfsTopoSort(int node, unordered_map<int, bool>& isVisited, stack<int>& s)
        {
            isVisited[node] = true;

            for(auto i: adj[node])
            {
                if(!isVisited[i.first])
                {
                    dfsTopoSort(i.first, isVisited, s);
                }
            }

            s.push(node);
        }

        // Finding shortest path from a source node:
        void getShortestPath(int source, vector<int>& dist, stack<int>& s)
        {
            dist[source] = 0;

            // Now check for each of the top element of the stack untill it becomes empty:
            while(!s.empty())
            {
                int top = s.top();
                s.pop();

                // if the element whose adj element you are checking itself have infinity distnce, then ignore it:
                if(dist[top] != INT_MAX)
                {
                    for(auto i: adj[top])
                    {
                        // Checking for the distace if it can be updated in the distance array:
                        if(dist[top] + i.second < dist[i.first])
                        {
                            dist[i.first] = dist[top] + i.second;
                        }
                    }
                }
            }
        }
};

int main()
{
    // Making Graph:
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // Printing Graph:
    g.printAdj();

    // Topological Sort:
    int noOfNodes = 6;
    unordered_map<int, bool> isVisited;
    stack<int> s;

    for(int i=0; i<noOfNodes; i++)
    {
        if(!isVisited[i])
        {
            g.dfsTopoSort(i, isVisited, s);
        }
    }

    // Make a distance array and initialize all of the elements except the source node as infinity and source node as 0:
    int source = 1;
    vector<int> dist(noOfNodes);
    for(int i=0; i<noOfNodes; i++)
    {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(source, dist, s);

    // Printing the distance vector after finding shortest path:
    cout << "Shortest Path to each node from 1 is: ";
    for(int i=0; i<noOfNodes; i++)
    {
        cout << dist[i] << ", ";
    }
    

    return 0;
}