#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template< class T >
class Graph
{
    public:
        unordered_map<T, list<T> > adj;

        void CreateEdge(T u, T v, bool direction)
        {
            // direction = 0 -> Undirected Graph
            // direction = 1 -> Directed Graph

            adj[u].push_back(v);

            if(direction == 0)
            {
                adj[v].push_back(u);
            }
        }

        void PrintAdjList()
        {
            for(auto i: adj)
            {
                cout << i.first << "->";
                for(auto j: i.second)
                {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int m;
    cout << "Enter the no of edges" << endl;
    cin >> m;

    Graph<int> g;

    // Creating an Undirected graph
    for(int i=0; i<m; i++)
    {
        cout << "Enter the Node values" << endl;
        int u, v;
        cin >> u >> v;
        g.CreateEdge(u, v, 0);
    }

    // Printing Graph
    g.PrintAdjList();

    return 0;
}