#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value), left(nullptr), right(nullptr){}
};

Node* insert(Node* root, int value)
{
    if(root==nullptr)
    {
        return new Node(value);
    }
    if(value < root->data)
    {
        root->left=insert(root->right, value);
    }
    else if(value > root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}

bool search(Node* root, int key)
{
    if(root==nullptr || root->data==key)
    {
        return(root!=nullptr);
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right, key);
    }
}

void inorderTraversal(Node* root)
{
    if(root!=nullptr)
    {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

int main()
{
    Node* root=nullptr;

    root = insert(root,2);
    insert(root,2);
    insert(root,4);
    insert(root,9);
    insert(root,4);
    insert(root,1);
    insert(root,5);
    insert(root,3);


    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;

    int KeyToSearch = 2;
    if(search(root, KeyToSearch))
    {
        cout<<KeyToSearch<<"is present in BST.\n";
    }
     else
    {
        cout<<KeyToSearch<<"is not present in BST.\n";
    }

    KeyToSearch = 3;
    if(search(root, KeyToSearch))
    {
        cout<<KeyToSearch<<"is present in BST.\n";
    }
    else
    {
        cout<<KeyToSearch<<"is not present in BST.\n";
    }

    KeyToSearch = 10;
    if(search(root, KeyToSearch))
    {
        cout<<KeyToSearch<<"is present in BST.\n";
    }
    else
    {
        cout<<KeyToSearch<<"is not present in BST.\n";
    }
    return 0;
}
