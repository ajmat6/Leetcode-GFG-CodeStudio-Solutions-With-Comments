class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // If root is null or the root is node we are finding:
        if(root == NULL || root == p || root == q) return root;

        // calling left and right subtrees to find the node p and q:
        TreeNode* left = solve(root -> left, p, q);
        TreeNode* right = solve(root -> right, p, q);

        // both sides are not null means p and q nodes are found:
        if(left != NULL && right != NULL) return root;

        // if on one side either p and q is found:
        else if(left != NULL && right == NULL) return left;
        else if(left == NULL && right != NULL) return right;

        // if no one of them is found:
        else return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = solve(root, p, q);
        return ans;
    }
};