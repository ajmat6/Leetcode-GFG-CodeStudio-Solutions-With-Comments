class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        Node* curr = root;
        vector<int> ans;
        
        while(curr != NULL)
        {
            if(curr -> left == NULL)
            {
                ans.push_back(curr -> data);
                curr = curr -> right;
            }
            
            // if root's left exist then making a connection so that we can come back
            else
            {
                Node* pred = curr -> left;
                while(pred -> right && pred -> right != curr) // second conditon is for the else condition below
                {
                    pred = pred -> right;
                }
                
                if(pred -> right == NULL)
                {
                    pred -> right = curr; // for making link for getting back iteratively
                    curr = curr -> left;
                }
                
                else
                {
                    pred -> right = NULL; // removing the link
                    ans.push_back(curr -> data);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};