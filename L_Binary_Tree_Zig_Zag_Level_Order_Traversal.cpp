class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v; //for storing elements at each level
        int i = 0;
        q.push(root);

        // if tree is NULL
        if(root == NULL)
        {
            return ans;
        }

        while(!q.empty())
        {
          int n = q.size();
          v.clear();

          while(n > 0)
          {
            TreeNode* temp = q.front();
            q.pop();

            v.push_back(temp -> val);

            if(temp -> left != NULL) q.push(temp -> left);
            if(temp -> right != NULL) q.push(temp -> right);

            n--;
          }

          // conditions for pushing into the ans vector
          if(i == 1)
          {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            i = 0;
          }
          else
          {
            ans.push_back(v);
            i = 1; 
          }
        }

        return ans;
    }
};