class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case:
        if(root == NULL)
        {
            return NULL;
        }

        // if both p and q are on left side then their LCA is on the left side
        if(root -> val > p -> val && root -> val > q -> val)
        {
            return lowestCommonAncestor(root -> left, p, q);
        }

        // if both p and q are on right side then their LCA is on the right side
        if(root -> val < p -> val && root -> val < q -> val)
        {
            return lowestCommonAncestor(root -> right, p, q);
        }

        // if both p and q are on different sides , then root is their common ancestor
        return root;
    }
};