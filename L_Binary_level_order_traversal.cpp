class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int n = q.size();

            while(n--)
            {
                TreeNode* tempo = q.front();
                q.pop();

                int data = tempo -> val;
                temp.push_back(data);

                if(tempo -> left)
                {
                    q.push(tempo -> left);
                }

                if(tempo -> right)
                {
                    q.push(tempo -> right);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};