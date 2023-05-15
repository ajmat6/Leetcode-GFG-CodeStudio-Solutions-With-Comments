vector<int> leftView(Node *root)
{
   vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int, int> mymap; // first value is vertical distance and the second value is node's data
        queue<pair<Node*, int>> q; // node and vertical distance
        q.push(make_pair(root, 0)); // pushing root node into the queue
        
        while(!q.empty())
        {
            pair<Node* , int> p = q.front();
            q.pop();
            Node* temp = p.first;
            int lvl = p.second;
            
            //checking if the value is present for lvl, if not then map it:
            if(mymap.find(lvl) == mymap.end())
            {
                mymap[lvl] = temp -> data;
            }
            
            // pushing left and right nodes of the tree if they are not null
            if(temp -> left)
            {
                q.push(make_pair(temp -> left, lvl+1));
            }
            
            if(temp -> right)
            {
                q.push(make_pair(temp -> right, lvl+1));
            }
        }
        
        // Pushing values into the ans vector:
        for(auto i: mymap)
        {
            ans.push_back(i.second);
        }
        
        return ans;
}