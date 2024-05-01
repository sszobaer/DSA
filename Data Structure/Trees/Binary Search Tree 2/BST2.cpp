#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}


bool search(Node* root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return (root != nullptr);
    }

    if (key > root->data)
    {
        return search(root->right, key);
    }

    return search(root->left, key);
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);


    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;


    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;


    int keyToSearch = 40;
    if (search(root, keyToSearch)) {
        cout << keyToSearch << " found in the tree." << endl;
    } else {
        cout << keyToSearch << " not found in the tree." << endl;
    }

    return 0;
}
