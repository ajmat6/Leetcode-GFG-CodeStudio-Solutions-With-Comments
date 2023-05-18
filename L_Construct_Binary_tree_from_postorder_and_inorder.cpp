class Solution {
public:
    // searching index of the node in inorder traversal that appeared in preorder  traversal
    void mapping(vector<int> in, int n, map<int, int>& mymap)
    {
        for(int i=0; i<n; i++)
        {
            mymap[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>in, vector<int> post, int &index, int inorderStart, int inorderEnd, int n, map<int, int>& mymap)
    {
        if(index < 0 || inorderStart > inorderEnd) return NULL;

        int element = post[index--];
        TreeNode* temp = new TreeNode(element);

        int position = mymap[element];

        temp -> right = solve(in, post, index, position+1, inorderEnd, n, mymap);
        temp -> left = solve(in, post, index, inorderStart, position-1, n, mymap);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postOrderIndex = n-1;
        map<int, int> mymap;
        mapping(inorder, n, mymap);
        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n, mymap);
        return ans;
    }
};