// inorder traversal:
    void inorder(TreeNode<int>* root, vector<TreeNode<int>*>& ans)
    {
        if(root == NULL) return;
        inorder(root -> left, ans);
        ans.push_back(root);
        inorder(root -> right, ans);
    }

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // if tree is empty:
    if(root == NULL) return NULL;

    // finding inorder traversal of the nodes of the BST
    vector<TreeNode<int>*> ans;
    inorder(root, ans);

    // pointing a node to the ans vector
    TreeNode<int>* temp = ans[0];
    TreeNode<int>* curr = temp;

    // pointing right pointer of the curr pointer to the next node of the vector and left to the NULL
    for(int i=0; i<ans.size()-1; i++)
    {
        curr -> right = ans[i+1];
        curr -> left = NULL;

        curr = curr -> right;
    }

    // last node pointing to the NULL for both left and right:
    curr -> left = NULL;
    curr -> right = NULL;

    return temp;
}