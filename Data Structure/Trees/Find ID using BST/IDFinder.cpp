#include <bits/stdc++.h>
using namespace std;

struct StudentNode
{
    int id;
    string name;
    double cgpa;
    StudentNode* left;
    StudentNode* right;

    StudentNode(int studentID, const std::string& studentName, double studentCGPA): id(studentID), name(studentName), cgpa(studentCGPA), left(nullptr), right(nullptr) {}
};

StudentNode* insert(StudentNode* root, int id, const string& name, double cgpa)
{
    if(root == nullptr)
    {
        return new StudentNode(id, name, cgpa);
    }
    if(id < root->id)
    {
        root->left=insert(root->left, id, name, cgpa);
    }
    else if (id > root->id)
    {
        root->right=insert(root->right, id, name, cgpa);
    }
    return root;
}

StudentNode* search(StudentNode*root, int id)
{
    if(root == nullptr || root->id == id)
    {
        return root;
    }
    if(id<root->id)
    {
        return search(root->left,id);
    }
    else
    {
        return search(root->right,id);
    }
}

void inorderTraversal(StudentNode* root)
{
    if(root != nullptr)
    {
        inorderTraversal(root->left);
        cout<<"ID: "<<root->id<<", Name: "<<root->name<<", CGPA: "<<root->cgpa<<endl;
        inorderTraversal(root->right);
    }
}

int main()
{
    StudentNode* root = nullptr;

    root = insert(root, 49415, "Zobaer", 3.57);
    insert(root, 49419, "Abid", 3.80);
    insert(root, 49393, "Efaz", 3.69);
    insert(root, 49385, "Nayeem", 3.80);
    insert(root, 49400, "Fahim", 2.55);
    insert(root, 43950, "Asif", 3.78);

    cout<<"Inorder Traversal(ID, Name, CGPA): \n";
    inorderTraversal(root);

    int searchID = 49415;
    StudentNode* result = search(root, searchID);

    if(result != nullptr)
    {
        cout<<"\n Student found (ID: "<< result->id << ", Name: " << result->name <<", CGPA: "<<result->cgpa<< ")\n";
    }
    else
    {
        cout<<"\n Student ID" << searchID<<"not found.\n";
    }

    return 0;
}

