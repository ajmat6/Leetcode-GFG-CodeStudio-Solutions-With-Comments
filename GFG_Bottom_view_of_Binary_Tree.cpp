class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int, int> mymap; // first value is horizontal distance and the second value is node's data
        queue<pair<Node*, int>> q; // node and horizontal distance
        q.push(make_pair(root, 0)); // pushing root node into the queue
        
        while(!q.empty())
        {
            pair<Node* , int> p = q.front();
            q.pop();
            Node* temp = p.first;
            int hd = p.second;
            
            // inserting the key value if not present and if present updating them:
            mymap[hd] = temp -> data;
            
            // pushing left and right nodes of the tree if they are not null
            if(temp -> left)
            {
                q.push(make_pair(temp -> left, hd-1));
            }
            
            if(temp -> right)
            {
                q.push(make_pair(temp -> right, hd+1));
            }
        }
        
        // Pushing values into the ans vector:
        for(auto i: mymap)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
