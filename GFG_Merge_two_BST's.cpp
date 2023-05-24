class Solution
{
    public:
    // creating inorder traversal of the BSTs
    void inorder(Node* root, vector<int>& ans)
    {
        if(root == NULL) return;
        inorder(root -> left, ans);
        ans.push_back(root -> data);
        inorder(root -> right, ans);
    }
    
    // Creating a merge array of the preorder of the final bst:
    vector<int> mergeInorderTraversal(vector<int>& ans1, vector<int>& ans2)
    {
        vector<int> FinalInorder (ans1.size() + ans2.size());
        int i = 0; 
        int j = 0;
        int k = 0;
        
        while(i < ans1.size() && j < ans2.size())
        {
            if(ans1[i] < ans2[j])
            {
                FinalInorder[k++] = ans1[i++];
            }
            
            else
            {
                FinalInorder[k++] = ans2[j++];
            }
        }
        
        while(i<ans1.size())
        {
            FinalInorder[k++] = ans1[i++];
        }
        
        while(j<ans2.size())
        {
            FinalInorder[k++] = ans2[j++];
        }
        
        return FinalInorder;
    }
    
    // Node* BSTCreation(vector<int>& ans, int start, int end)
    // {
    //     if(start > end)
    //     {
    //         return NULL;
    //     }
        
    //     int mid = start + end / 2;
        
    //     Node* root = new Node(ans[mid]);
    //     root -> left = BSTCreation(ans, start, mid - 1);
    //     root -> right = BSTCreation(ans, mid + 1, end);
        
    //     return root;
    // }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> inorder1;
        vector<int> inorder2;
        
        inorder(root1, inorder1);
        inorder(root2, inorder2);
        
        vector<int> ans = mergeInorderTraversal(inorder1, inorder2);
        
        // int n = ans.size();
        
        // return BSTCreation(ans, 0, n-1);
        
        return ans;
    }
};