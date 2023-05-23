class Solution {
public:
    // inorder traversal:
    void inorder(TreeNode* root, vector<TreeNode*>& ans)
    {
        if(root == NULL) return;
        inorder(root -> left, ans);
        ans.push_back(root);
        inorder(root -> right, ans);
    }

    // Building a Balanced BST through inorder Traversal:
    TreeNode* BalancedBST(vector<TreeNode*>& ans, int start, int end)
    {
        // Base Condition:
        if(start > end) return NULL;

        // finding mid to make root node:
        int mid = (start + end )/ 2;

        // making root node and calling recursively for the right and left node:
        TreeNode* root = ans[mid];
        root -> left = BalancedBST(ans, start, mid - 1);
        root -> right = BalancedBST(ans, mid+1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> ans;
        inorder(root, ans);

        return BalancedBST(ans, 0, ans.size()-1);
    }
};