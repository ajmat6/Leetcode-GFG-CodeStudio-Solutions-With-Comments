class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& path, int& count)
    {
        // Base condition
        if(root == NULL)
        {
            return;
        }

        // Pushing current root data into the vector
        path.push_back(root -> val);

        // Calling solve function recursively for left and right subtrees
        solve(root -> left, targetSum, path, count);
        solve(root -> right, targetSum, path, count);

        // Checking for the sum
        long long int sum = 0;
        for(long long int i=path.size()-1; i>=0; i--)
        {
            sum += path[i];
            if(sum == targetSum) count++;
        }

        // Popping one element from the vector at each step
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;
        solve(root, targetSum, path, count);
        return count;
    }
};