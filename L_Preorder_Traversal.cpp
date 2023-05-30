class Solution {
public:
    void PreOrder(TreeNode*& root, vector<int>& ans)
    {
        if(root == NULL) return;

        ans.push_back(root -> val);
        PreOrder(root -> left, ans);
        PreOrder(root -> right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PreOrder(root, ans);
        return ans;
    }
};