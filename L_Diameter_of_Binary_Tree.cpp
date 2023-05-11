class Solution {
    pair<int,int> diameter(TreeNode* root)
    {
        //base condition
        if(root == NULL)
        {
            pair<int,int> p = make_pair(0,0); //storing base condition pair values
            return p;
        }

        pair<int,int> left = diameter(root -> left);
        pair<int,int> right = diameter(root -> right);

        int leftside = left.first; //left side of node height
        int rightside = right.first; //right side of the node height
        int total = left.second + right.second; //total height excluding node

        pair<int,int> ans;
        ans.first = max(total, max(leftside, rightside)); //storing diameter at each node
        ans.second = max(left.second, right.second) + 1; //storing height at each node

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first; //returning first value of piars as it stores diameter
    }
};