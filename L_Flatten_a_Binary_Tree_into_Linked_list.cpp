class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;

        while(current != NULL)
        {
            if(current -> left)
            {
                // Search for the inorder predecessor
                TreeNode* pred = current -> left;
                while(pred -> right)
                {
                    pred = pred -> right;
                }

                // Joining inorder predecessor of a node to its right child and then breaking the linkage of the node with its right child and making it equal to its left child
                pred -> right = current -> right;
                current -> right = current -> left;

                // Making left Nodes as NULL
                current -> left = NULL;
            }
            // if left does not exist then move to the right part
            current = current -> right;
        }
    }
};