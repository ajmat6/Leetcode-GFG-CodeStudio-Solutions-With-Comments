class Solution {
public:
    vector<int> rightView(TreeNode* root, vector<int>& ans, int level)
    {
        // Base condition
        if(root == NULL) return ans;

        // Pushing in the ans vector only if below condition met
        if(level == ans.size())
        {
            ans.push_back(root -> val);
        }
 
        // calling recursively for left and right subtrees
        if(root -> right) rightView(root -> right, ans, level+1);
        if(root -> left) rightView(root -> left, ans, level+1);

        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        return rightView(root, ans, level);
    }
};