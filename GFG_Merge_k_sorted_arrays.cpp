// TC = O(n*KlogK) -> as size of priority queue is K and we are inserting each element of the K arrays of size n into the Min Heap
// SC = O(n*k) -> Min Heap SC = O(K) as  it is  of size K and ans vector is of size n*k where n is size of each K arrays.Therefore required SC.

// Our own DS for the track of the array whose element has been inserted into the ans vector
class Node
{
    public:
    int data; // Data of the array element
    int i;    // row no (array no)
    int j;    // array index no
    
    Node(int data, int row, int col) // constructor for initialiazing above values
    {
        this -> data = data;
        this -> i = row;
        this -> j = col;
    }
};

// MinHeap greater function for our custom DS as it is not int
class MyGreater
{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a -> data > b -> data;
    }
};

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, MyGreater> q;
        
        // Insert all k arrays first Element into the Min Heap:
        for(int i=0; i<K; i++)
        {
            Node* temp = new Node(arr[i][0], i, 0);
            q.push(temp);
        }
        
        vector<int> ans;
        
        // Insert top element of the heap into the ans vector and keeping track of the array whose element has been inserted:
        while(!q.empty())
        {
            Node* top = q.top();
            ans.push_back(top -> data);
            q.pop();
            
            int i = top -> i;
            int j = top -> j;
            
            if(j+1 < arr[i].size())
            {
                Node* NewNode = new Node(arr[i][j+1], i, j+1);
                q.push(NewNode);
            }
        }
        
        return ans;
    }
};