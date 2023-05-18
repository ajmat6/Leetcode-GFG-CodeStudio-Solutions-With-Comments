class Solution {
  public:
    // this function will map the node with its parent and also give us the targetNode
    Node* ParentMapping(Node* root, int target, map<Node*, Node*>& NodetoParent)
    {
        queue<Node*> q;
        NodetoParent[root] = NULL; // No parent of root node
        q.push(root);
        Node* resultantTarget = NULL; // marking targetnode as null 
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            // storing the targetnode
            if(temp -> data == target)
            {
                resultantTarget = temp;
            }
            
            // if left and right node exist then map them with their parent and push them into the queue for the levelorder traversal
            if(temp -> left)
            {
                q.push(temp -> left);
                NodetoParent[temp -> left] = temp;
            }
            if(temp -> right)
            {
                q.push(temp -> right);
                NodetoParent[temp -> right] = temp;
            }
        }
        
        return resultantTarget;
    }
    
    int BurntheTree(map<Node*, Node*> NodeParent, Node* targetNode)
    {
        // keeping track of the burned nodes
        map<Node*, bool> visited;
        
        // to check for a node and then burn their children and parent
        queue<Node*> q;
        
        visited[targetNode] = true;
        q.push(targetNode);
        
        int ans = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            bool ifAdded = false;
            
            // Checking and processing for its neighbours
            for(int i=0; i<size; i++)
            {
                Node* temp = q.front();
                q.pop();
                
                // for the parent Node
                Node* parent = NodeParent[temp];
                if(parent && !visited[parent])
                {
                    q.push(parent);
                    visited[parent] = true;
                    ifAdded = true;
                }
                
                // for the left node
                if(temp -> left && !visited[temp -> left])
                {
                    q.push(temp -> left);
                    visited[temp -> left] = true;
                    ifAdded = true;
                }
                
                // for the right node
                if(temp -> right && !visited[temp -> right])
                {
                    q.push(temp -> right);
                    visited[temp -> right] = true;
                    ifAdded = true;
                }
                
            }
            
            // incremeting the burn time if addition is done in the queue
            if(ifAdded)
            {
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> NodetoParent;
        Node* targetNode = ParentMapping(root, target, NodetoParent);
        
        int ans = BurntheTree(NodetoParent, targetNode);
        return ans;
    }
};