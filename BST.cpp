#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void levelorder(Node* root)
{
    queue<Node*> q; //whole node will be pushed and popped
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp -> data << " ";

            if(temp -> left != NULL) //agar sahi he to hi queue me daal
            {
                q.push(temp -> left);
            }

            if(temp -> right != NULL)
            {
                q.push(temp -> right);
            }   
        }    
    }
}

void inorder(Node* root)
{
    if(root == NULL) return ;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root)
{
    if(root == NULL) return ;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root)
{
    if(root == NULL) return ;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

Node* insertIntoBST(Node* root, int data)
{
    // base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // right node case
    if(data > root -> data)
    {
        root -> right = insertIntoBST(root -> right, data);
    }

    // left node case
    if(data < root -> data)
    {
        root -> left = insertIntoBST(root -> left, data);
    }
    
    return root;
}

void Input(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minValue(Node* root)
{
    Node* temp = root;

    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }

    return temp;
}

Node* maxValue(Node* root)
{
    Node* temp = root;

    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int value)
{
    // Base case
    if(root == NULL) return root;

    // if node to be deleted is found:
    if(root -> data == value)
    {
        // if node to be deleted is leaf node:
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        // if node to be deleted is a node with one child:
        if(root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        if(root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // if node to be deleted is a node in between:
        if(root -> left && root -> right)
        {
            // finding inorder successor:
            Node* temp = root -> right;
            Node* minNode = minValue(temp);

            // copying the root data with the inorder successor:
            root -> data = minNode -> data;

            // now deleting the inorder successor as you have replaced root with it:
            root -> right = deleteFromBST(root -> right, minNode -> data);

            // return root:
            return root;
        }
    }

    // value lesser than curr node -> go in left part
    else if(root -> data > value)
    {
        root -> left = deleteFromBST(root -> left, value);
        return root;
    }

    // value greater than curr node -> go in right part
    else if(root -> data < value)
    {
        root -> right = deleteFromBST(root -> right, value);
        return root;
    }
}

int main()
{
    // 50 20 70 10 30 90 110 -1
    Node* root = NULL;

    cout<< "Enter the data into the BST" << endl;
    Input(root);

    levelorder(root);

    // inorder traversal
    cout << "Inorder traversal is " << endl;
    inorder(root);
    cout << endl;

    cout << "Min value in the given tree is " << minValue(root) -> data << endl;
    cout << "Max value in the given tree is " << maxValue(root) -> data << endl;

    cout << "Printing the BST after deleting the nodes: " << endl;
    root = deleteFromBST(root, 50);

    inorder(root);
    cout << endl;
    levelorder(root);

    return 0;
}