
#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* right;
    Node* left;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* create_tree(Node* root)
{
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data to the left of "<<data<<endl;
    root->left = create_tree(root->left);

    cout<<"Enter data to the right of "<<data<<endl;
    root->right = create_tree(root->right);

    return root;
}

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return (max(height(root->left),height(root->right))+1);

}

int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = (height(root->left) + height(root->right)+1);

    return (max(d3, max(d1,d2)));

}

int main()
{
    Node* root = NULL;
    root = create_tree(root);

    cout<<"Height of tree "<<height(root)<<endl;
    cout<<"Diameter of tree "<<diameter(root)<<endl;

    return 0;
}