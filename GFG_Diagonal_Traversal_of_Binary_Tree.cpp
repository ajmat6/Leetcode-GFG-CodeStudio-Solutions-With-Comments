vector<int> diagonal(Node *root)
{
   vector<int> ans;
 
   if(root == NULL) return ans;
   
   queue<Node*> q;
   
   // Iterating through the tree untill root becomes NULL
   while(root != NULL)
   {
       // Pushing current root data into the ans vector
       ans.push_back(root -> data);
       
       if(root -> left) q.push(root -> left);// if root's left is not null and lining it up in queue
       if(root -> right) root = root -> right; // Going for the right side if it is not NULL
       
       // if root's right is null then looking up for the first left side element in the queue
       else
       {
           if(!q.empty())
           {
               root = q.front();
               q.pop();
           }
           // right side is NULL and queue is empty means there is no left side. It means complete tree traversal is done
           else
           {
               root = NULL;
           }
       }
   }
}