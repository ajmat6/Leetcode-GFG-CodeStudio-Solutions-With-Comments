Node* solve(Node* root, int& k, int node)
{
    if(root == NULL || root -> data == node) return root;
    
    Node* left = solve(root -> left, k, node);
    Node* right = solve(root -> right, k, node);
    
    // if node is found, decrease k value and if it becomes zero return that root node otherwise return found node
    if(left != NULL && right == NULL)
    {
        k--;
        if(k == 0)
        {
            return root;
        }
        
        else return left;
    }
    
    else if(left == NULL && right != NULL)
    {
        k--;
        if(k == 0)
        {
            return root;
        }
        else return right;
    }
    
    // if node not found
    else if(left == NULL && right == NULL) return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    
    // if node not found or node is either root node and the k's value is greater than height of the node( k ki value zero nahi hui , kth ancestor nahi mila)
    if(ans == NULL || ans -> data == node) return -1;
    else return ans -> data;
}
