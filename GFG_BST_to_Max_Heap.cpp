class Solution{
  public:
    // first find inorder traversal of the BST
    void inorder(Node* root, vector<int>& ans)
    {
        if(root == NULL) return;
        
        inorder(root -> left, ans);
        ans.push_back(root -> data);
        inorder(root -> right, ans);
    }
    
    // Now fill the tree as postorder traversal using its inorder traversal -> How??
    // N > L , N > R , R > L ==> L < R < N which is postorder traversal
    void FillTree(Node* root, vector<int>& ans, int& index)
    {
        if(root == NULL) return;
        FillTree(root -> left, ans, index);
        FillTree(root -> right, ans, index);
        root -> data = ans[index++];
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> ans;
        inorder(root, ans);
        
        int i = 0;
        FillTree(root, ans, i);
    }    
};