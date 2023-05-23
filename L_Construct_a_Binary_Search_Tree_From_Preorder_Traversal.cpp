class Solution {
public:
    TreeNode* solve(int low, int high, vector<int>& preorder, int& index)
    {
        // Base Cases: if you have traversed whole preorder vector or the node is not fit to be inserted at that position (not in range of low and high)
        if(index == preorder.size()) return NULL;
        if(preorder[index] < low || preorder[index] > high)
        {
            return NULL;
        }
        
        // if in range creating a node and calling recursively for left and right node:
        TreeNode* root = new TreeNode(preorder[index++]);
        root -> left = solve(low, root -> val, preorder, index);
        root -> right = solve(root -> val, high, preorder, index);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // setting iniitial ranges
        int low = INT_MIN; 
        int high = INT_MAX;
        int index = 0;

        return solve(low, high, preorder, index);
    }
};