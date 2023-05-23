class Solution{
  public:
    // inorder traversal:
    void inorder(struct Node* root, vector<int>& ans)
    {
        if(root == NULL) return;
        inorder(root -> left, ans);
        ans.push_back(root -> data);
        inorder(root -> right, ans);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
        // finding inorder traversal
        vector<int> ans;
        inorder(root, ans);
        
        // applying two pointer approach to find if such a pair exist
        int i = 0;
        int j = ans.size() - 1;
        int flag = 0;
        
        while(i < j)
        {
            if(ans[i] + ans[j] == target)
            {
                flag = 1;
                break;
            }
            
            else if(ans[i] + ans[j] > target)
            {
                j--;
            }
            
            else
            {
                i++;
            }
        }
        
        if(flag == 1) return 1;
        else return 0;
    }
};