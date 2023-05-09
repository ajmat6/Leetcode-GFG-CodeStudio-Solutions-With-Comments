#include<iostream>
#include<queue>
using namespace std;

//class to initialize the tree
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Creating tree recursively

node* createTree(node* root)
{
    cout<< "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1) return NULL; //condition for the null (end of the tree)


    cout << "Enter the left children of "<<data<< endl;
    root -> left = createTree(root -> left);

    cout << "Enter the right children of "<<data<< endl;
    root -> right = createTree(root -> right);

    return root;
}

// LevelOrder Traversal

void levelorder(node* root)
{
    queue<node*> q; //whole node will be pushed and popped
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
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

// Inorder Preorder ans Postorder Traversal

void inorder(node* root)
{
    if(root == NULL) return ;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(node* root)
{
    if(root == NULL) return ;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root)
{
    if(root == NULL) return ;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

// Building tree from levelorder traversal
void BuildTreeFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout << "Enter Data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        // if(temp != NULL)
        // {
            cout << "Enter the left child of " << temp -> data << endl;
            int leftchild;
            cin >> leftchild;
            if(leftchild != -1)
            {
                temp -> left = new node(leftchild);
                q.push(temp -> left);
            }

            cout << "Enter the right child of " << temp -> data << endl;
            int rightchild;
            cin >> rightchild;
            if(rightchild != -1)
            {
                temp -> right = new node(rightchild);
                q.push(temp -> right);
            }
        // }
    }
}

int main()
{
    node* root = NULL;
    // root = createTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // cout << "Levelorder traversal is " << endl;
    // levelorder(root);

    // cout << "Inorder Traversal is " << endl;
    // inorder(root);
    // cout << endl;

    // cout << "preorder Traversal is " << endl;
    // preorder(root);
    // cout << endl;

    // cout << "postorder Traversal is " << endl;
    // postorder(root);

    cout<< endl;
    cout << "Tree from levelorder traversal is " << endl;
    BuildTreeFromLevelOrder(root);

    cout << "Levelorder traversal is " << endl;
    levelorder(root);

    return 0;
}