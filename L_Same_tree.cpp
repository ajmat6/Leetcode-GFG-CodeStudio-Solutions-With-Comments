class Solution
{
    public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL) return true;
        else if(r1 == NULL && r2 != NULL) return false;
        else if(r1 != NULL && r2 == NULL) return false;
        
        else if(r1 -> data == r2 -> data)
        {
            bool left = isIdentical(r1 -> left, r2 -> left);
            bool right = isIdentical(r1 -> right, r2 -> right);
            
            if(left && right) return true;
            else return false;
        }
        
        else return false;
    }
};