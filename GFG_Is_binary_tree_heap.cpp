class Solution {
  public:
    int countNodes(struct Node* tree)
    {
        int count = 0;
        
        if(tree == NULL) return 0;
        
        int left = countNodes(tree -> left);
        int right = countNodes(tree -> right);
        
        return left + right + 1;
    }
    
    bool isCBT(struct Node* tree, int index, int totalNodes)
    {
        if(tree == NULL) return true;
        
        if(index >= totalNodes) return false;
        
        bool left = isCBT(tree -> left, 2*index+1, totalNodes);
        bool right = isCBT(tree -> right, 2*index+2, totalNodes);
        
        return (left && right);
    }
    
    bool isMaxHeap(struct Node* tree)
    {
        if(tree -> left == NULL && tree -> right == NULL) return true;
        
        if(tree -> right == NULL)
        {
            if(tree -> data < tree -> left -> data) return false;
            else return true;
        }
        
        else
        {
            bool left = isMaxHeap(tree -> left);
            bool right = isMaxHeap(tree -> right);
            
            if(left && right && (tree -> data > tree -> left -> data && tree -> data > tree -> right -> data))
            {
                return true;
            }
            else return false;
        }
    }
    
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalNodes = countNodes(tree);
        
        if(isCBT(tree, index, totalNodes) && isMaxHeap(tree)) return true;
        else return false;
    }
};
