class Solution
{
    public:
    pair<int, int> isSum(Node* root)
    {
        //base condition:
        if(root == NULL)
        {
            pair<int, int> p = make_pair(true, 0);
            return p;
        }
        
        //leaf node condition:
        if(root -> left == NULL && root -> right == NULL)
        {
            pair<int, int> p = make_pair(true, root -> data);
            return p;
        }
        
         //storing returned ans for the left and right subtree
         pair<int, int> left = isSum(root -> left);
         pair<int, int> right = isSum(root -> right);
         
         //checking left and right subtree if it is sum tree or not:
         bool leftside = left.first;
         bool rightside = right.first;
         bool sum = root -> data == left.second + right.second;
            
         // storing final ans for each subtree    
         pair<bool, int> ans;
         ans.second = root -> data + left.second + right.second;
         
         //return conditions
         if(leftside && rightside && sum)
         {
            ans.first = true;
         }
         else
         {
            ans.first = false; 
         }
         
         return ans;
    }
    
    bool isSumTree(Node* root)
    {
         return isSum(root).first;
    }
};