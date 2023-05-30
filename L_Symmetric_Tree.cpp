class Solution {
public:
    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) return true; // both should have leaf nodes at the same time -> return true
        if(root1 == NULL || root2 == NULL) return false; // otherwise return false

        // checking for the left and right nodes symmetricness:
        if(root1 -> val == root2 -> val)
        {
            return isMirror(root1 -> left, root2 -> right) && isMirror(root1 -> right, root2 -> left);
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isMirror(root -> left, root -> right);
    }
};