class Solution {
public:
    // counting the no of nodes in the LL:
    int countNodes(ListNode* root)
    {
        int count = 0;
        while(root != NULL)
        {
            count++;
            root = root -> next;
        }
        return count;
    }

    TreeNode* LLtoBST(ListNode* &head, int n)
    {
        // Base case
        if(n <= 0 || head == NULL) return NULL;
    
        // for the left subtrees
        TreeNode* leftNode = LLtoBST(head, n/2);
    
        // creating a node
        TreeNode* temp = new TreeNode(head -> val);
        temp -> left = leftNode;
    
        // increaing the head node in the ll:
        head = head -> next;
    
        // for the right subtree
        temp -> right = LLtoBST(head, n-n/2-1);
    
        return temp;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int nodes = countNodes(head);
        return LLtoBST(head, nodes);
    }
};