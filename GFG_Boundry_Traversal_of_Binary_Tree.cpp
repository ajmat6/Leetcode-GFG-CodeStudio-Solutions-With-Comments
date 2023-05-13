class Solution {
public:
    void leftNode(Node* root, vector<int>& ans)
    {
        //base condition:
        if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        {
            return;
        }
        
        ans.push_back(root -> data);
        
        if(root -> left) leftNode(root -> left, ans);
        else leftNode(root -> right, ans);
    }
    
    void leafNode(Node* root, vector<int>& ans)
    {
        //base condition:
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> data);
            return;
        }
        
        leafNode(root -> left, ans);
        leafNode(root -> right, ans);
    }
    
    void rightNode(Node* root, vector<int>& ans)
    {
        //base condition:
        if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        {
            return;
        }
        
        ans.push_back(root -> data);
        
        if(root -> right) rightNode(root -> right, ans);
        else rightNode(root -> left, ans);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        //base conditions:
        if(root == NULL) return ans;
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> data);
            return ans;
        }
        
        //storing root node
        ans.push_back(root -> data);
        
        //storing left part of the root
        leftNode(root -> left, ans);
        
        //storing left leaf nodes of the root
        leafNode(root -> left, ans);
        
        //storing right leaf nodes of the root
        leafNode(root -> right, ans);
        
        //creating vector for storing right part of the tree
        vector<int> right;
        
        //storing right part of the tree
        rightNode(root -> right, right);
        
        //reversing the right vector
        reverse(right.begin(), right.end());
        
        //pushing right part of the tree into the ans vector
        for(auto i: right)
        {
            ans.push_back(i);
        }

        return ans;
    }
};