class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0; // NULL node height is zero
        }

        int left = height(root -> left);
        int right = height(root -> right);

        int ans = max(left, right) + 1; // max of right and left node height and adding 1 (of that current node) and returning it
        return ans;
    }

    int maxDepth(TreeNode* root) {
        int count = height(root);
        return count;
    }
};