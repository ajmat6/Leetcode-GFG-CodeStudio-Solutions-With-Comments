class Solution {
  public:
    void inorder(Node* root, vector<int>& ans)
        {
            if(root == NULL) return;
    
            inorder(root -> left, ans);
            ans.push_back(root -> data);
            inorder(root -> right, ans);
        }
    int KthSmallestElement(Node *root, int K) {
        vector<int> ans;
        inorder(root, ans);
        
        if(ans.size() < K) return -1;

        return ans[K-1];
    }
};