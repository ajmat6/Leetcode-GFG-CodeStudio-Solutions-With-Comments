class Solution {
public:
    bool isBST(TreeNode* root, long x, long y)
    {
        if(root == NULL) return true;

        if(root -> val > x && root -> val < y)
        {
            bool left = isBST(root -> left, x, root -> val);
            bool right = isBST(root -> right, root -> val, y);

            if(left && right) return true;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};