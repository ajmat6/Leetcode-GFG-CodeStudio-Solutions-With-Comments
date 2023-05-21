Node* insertNode(Node* root, int key)
    {
        if(root == NULL)
        {
            root = new Node(key);
            return root;
        }
        else if(key > root -> data) root -> right = insertNode(root -> right, key);
        else if(key < root -> data) root -> left= insertNode(root -> left, key);

        return root;
    }
Node* insert(Node* root, int Key) {
    // Node* newNode = new node(Key);
    return insertNode(root, Key);
}