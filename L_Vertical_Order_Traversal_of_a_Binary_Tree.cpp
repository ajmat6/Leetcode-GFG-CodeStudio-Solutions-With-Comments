class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int> > > mymap; // for storing horizontal distance, vetical level and at that level's node's value
        queue<pair<TreeNode*, pair<int , int> > > q; // for level order traversal
        vector<vector<int>> ans;

        if(root == NULL) return ans; // base condition

        q.push(make_pair(root, make_pair(0,0))); // pushing root node

        while(!q.empty())
        {
            pair<TreeNode*, pair<int, int> > p = q.front();
            q.pop();

            TreeNode* frontNode = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;

            mymap[hd][lvl].push_back(frontNode -> val); // mapping into mymap

            if(frontNode -> left) // if left subtree is not null
            {
                q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1)));
            }

            if(frontNode -> right) // if right subtree is not null
            {
                q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1)));
            }
        }

        for(auto i: mymap)
        {
            vector<int> temp; // creating temp vector for pushing into the 2d ans vector
            for(auto j: i.second) // traversing in map inside the map
            {
                sort(j.second.begin(), j.second.end());
                for(auto k: j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};