
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

int msp(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            return root->data;
        }
        else
        {
            int l = msp(root->left);
            int r = msp(root->right);
            int m = max(l,r);

            return (root->data + m);

        }
    }
}

int main()
{
    Node* root = NULL;
    root = create_tree(root);

    cout<<"Maximum Sum Path "<<msp(root);

    return 0;
}