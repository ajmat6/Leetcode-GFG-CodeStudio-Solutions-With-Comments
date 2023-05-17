class Solution{
    // searching index of the node in inorder traversal that appeared in preorder traversal
    int Search(int in[], int element, int start, int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(in[i] == element) return i;
        }
        return -1;
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
    {
        // No of nodes have either finished in preorder vector or left and right subnodes does not exist
        if(index >= n || inorderStart > inorderEnd) return NULL;

        // creating node
        int element = pre[index++];
        Node* temp = new Node(element);

        // finding the position of the node in the inorder traversal
        int position = Search(in, element, inorderStart, inorderEnd);

        // recursive calls
        temp -> left = solve(in, pre, index, inorderStart, position-1, n);
        temp -> right = solve(in, pre, index, position+1, inorderEnd, n);

        return temp;
    }
   
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};