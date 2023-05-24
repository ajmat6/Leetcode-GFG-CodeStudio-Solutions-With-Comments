// Creating a class as we are storing four values
class maxSum 
{
public:
    int maxi; // to check max value in a subtree
    int mini; // to check min value in a subtree
    int sum; // to check our ans NodesSum ans temporarily sum
    bool isBST; // to pass if subtree is a valid BST or not
};

class Solution {
public:
    maxSum solve(TreeNode* root, int& NodesSum) // returns an object
    {
        //Base Case
        if(root == NULL)
        {
            maxSum temp;
            temp.maxi = INT_MIN; // IMP to concentrate 
            temp.mini = INT_MAX; // IMP to concentrate
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }

        maxSum left = solve(root -> left, NodesSum);
        maxSum right = solve(root -> right, NodesSum);

        maxSum currentNode;
        currentNode.maxi = max(root -> val, right.maxi);
        currentNode.mini = min(root -> val, left.mini);
        currentNode.sum = left.sum + right.sum + root -> val;

        if(left.isBST && right.isBST && (root -> val > left.maxi && root -> val < right.mini))
        {
            currentNode.isBST = true;
        }

        else
        {
            currentNode.isBST = false;
        }

        if(currentNode.isBST)
        {
            NodesSum = max(NodesSum, currentNode.sum);
        }

        return currentNode;
    }

    int maxSumBST(TreeNode* root) {
        // max BST nodes sum
        int NodesSum = 0;
        maxSum ans = solve(root, NodesSum);
        return NodesSum;
    }
};