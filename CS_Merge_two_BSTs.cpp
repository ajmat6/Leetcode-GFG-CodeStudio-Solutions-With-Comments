#include <bits/stdc++.h> 

// converting the BST into doubly LL:
void convertIntoLinkedList(TreeNode<int> *root, TreeNode<int>* &head)
{
    if(root == NULL) return;

    convertIntoLinkedList(root -> right, head);

    root -> right = head;
    if(head != NULL)
    {
        head -> left = root;
    }

    head = root;
    
    convertIntoLinkedList(root -> left, head);
}

// Merging two sorted LL:
TreeNode<int>* MergeLL(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(root1 != NULL && root2 != NULL)
    {
        if(root1 -> data < root2 -> data)
        {
            if(head == NULL)
            {
                head = root1;
                tail = root1;
                root1 = root1 -> right;
            }

            else
            {
                tail -> right = root1;
                root1 -> left = tail;
                tail = root1;
                root1 = root1 -> right;
            }
        }
        
        else
        {
            if(head == NULL)
            {
                head = root2;
                tail = root2;
                root2 = root2 -> right;
            }

            else
            {
                tail -> right = root2;
                root2 -> left = tail;
                tail = root2;
                root2 = root2 -> right;
            }
        }
    }

    while(root1 != NULL)
    {
        tail -> right = root1;
        root1 -> left = tail;
        tail = root1;
        root1 = root1 -> right;
    }

    while(root2 != NULL)
    {
        tail -> right = root2;
        root2 -> left = tail;
        tail = root2;
        root2 = root2 -> right;
    }

    return head;
}

// counting the no of nodes in the LL:
int countNodes(TreeNode<int> *root)
{
    int count = 0;
    while(root != NULL)
    {
        count++;
        root = root -> right;
    }
    return count;
}

// converting sorted LL to a BST:
TreeNode<int>* LLtoBST(TreeNode<int>* &head, int n)
{
    // Base case
    if(n <= 0 || head == NULL) return NULL;

    TreeNode<int>* leftNode = LLtoBST(head, n/2);

    TreeNode<int>* temp = head;
    temp -> left = leftNode;

    head = head -> right;

    temp -> right = LLtoBST(head, n-n/2-1);

    return temp;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // conveting both BSTs into the LL:
    TreeNode<int>* List1 = NULL;
    convertIntoLinkedList(root1, List1);
    List1 -> left = NULL;
    
    TreeNode<int>* List2 = NULL;
    convertIntoLinkedList(root2, List2);
    List2 -> left = NULL;

    // Merge two LL:
    TreeNode<int>* head = MergeLL(List1, List2);

    //Make BST from the LL:
    int Nodes = countNodes(head);
    return LLtoBST(head, Nodes);
}