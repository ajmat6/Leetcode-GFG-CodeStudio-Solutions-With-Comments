class Solution{
  public:
    pair<int, int> solve(Node* root)
    {
        if(root == NULL)
        {
            // first value in a pair is its data included and second value is its data excluded
            pair<int, int> s = make_pair(0,0);
            return s;
        }
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        pair<int, int> ans;
        // ans pair first value has some of its own data + its left and right children own excluded data
        ans.first = root -> data + left.second + right.second;
        
        // second value of ans pair is sum of max of left and right children excluded and included data
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        return ans;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};