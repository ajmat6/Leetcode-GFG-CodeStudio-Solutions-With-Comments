void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp = root;
    pre = NULL;
    suc = NULL;
    
    // Successor
    while(temp)
    {
        if(temp -> key > key)
        {
            suc = temp; // storing the succ
            temp = temp -> left;
        }
        
        else
        {
            temp = temp -> right;
        }
    }
    
    // Predecessor
    while(root)
    {
        if(root -> key < key)
        {
            pre = root; // storing the pred
            root = root -> right;
        }
        
        else
        {
            root = root -> left;
        }
    }
}