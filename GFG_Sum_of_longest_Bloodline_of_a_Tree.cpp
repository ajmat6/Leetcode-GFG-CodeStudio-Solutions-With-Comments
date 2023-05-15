class Solution
{
public:
    void maxiSum(Node* root, int length, int sum, int& maxLength, int& maxSum)
    {
        // Base condition
        if(root == NULL)
        {
            if(length > maxLength)
            {
                maxLength = length;
                maxSum = sum;
            }
            
            if(length == maxLength)
            {
                maxSum = max(maxSum, sum);
            }
            
            return;
        }
        
        // storing sum in temporary sum:
        sum += root -> data;
        
        // Call for left and right subtrees:
        maxiSum(root -> left, length+1, sum, maxLength, maxSum);
        maxiSum(root -> right, length+1, sum, maxLength, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int length = 0; // temporary max path length
        int sum = 0; // temporary sum
        int maxLength = 0;
        int maxSum = INT_MIN;
        
        maxiSum(root, length, sum, maxLength, maxSum);
        return maxSum;
    }
};