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

int main()
{
    Node* root = NULL;

    cout<< "Enter the data into the BST" << endl;
    Input(root);

    levelorder(root);

    return 0;
}