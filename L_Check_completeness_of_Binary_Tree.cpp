class Solution {
public:
    // function to find total nodes in the binary tree:
    int count(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = count(root -> left);
        int right = count(root -> right);

        return left + right + 1;
    }

    // function for checking complete binary tree
    bool isCBT(TreeNode* root, int index, int totalNode)
    {
        if(root == NULL) return true;
        if(index >= totalNode) return false; // if current node index becomes equal or exceeds the total no of nodes

        bool left = isCBT(root -> left, 2*index+1, totalNode);
        bool right = isCBT(root -> right, 2*index+2, totalNode);

        return left && right;
    }

    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalNodes = count(root);

        return isCBT(root, index, totalNodes);
    }
};