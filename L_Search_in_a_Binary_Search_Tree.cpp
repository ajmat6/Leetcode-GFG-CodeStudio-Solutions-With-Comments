class Solution {
public:
    TreeNode* search(TreeNode* root, int val)
    {
        if(root == NULL || root -> val == val) return root;
        else if(root -> val > val) root = search(root -> left, val);
        else if(root -> val < val) root = search(root -> right, val);

        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = search(root, val);
        return ans;
    }
};