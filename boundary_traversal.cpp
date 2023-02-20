
#include<vector>
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};   

Node* create_tree()
{
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }
    else
    {
        Node* root= new Node(data);

        cout<<"Enter for left of "<<root->data<<endl;
        root->left = create_tree();

        cout<<"Enter for right of "<<root->data<<endl;
        root->right = create_tree();

        return root;
    }
}

void traverse_left(Node* root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    // handle when root->left == NULL

    ans.push_back(root->data);
    if(root->left)
    {
        traverse_left(root->left,ans);
    }
    else
    {
        traverse_left(root->right,ans);
    }
    
}

void traverse_leaf(Node* root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
    }

    traverse_leaf(root->left,ans);
    traverse_leaf(root->right,ans);

}

void traverse_right(Node* root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    
    if(root->right)
    {
        traverse_right(root->right,ans);
    }
    else
    {
        traverse_right(root->left,ans);
    }

    ans.push_back(root->data);
    
}

void boundary_traversal(Node* root)
{
    vector<int> ans;
    ans.push_back(root->data);

    traverse_left(root->left,ans);
    
    traverse_leaf(root->left,ans);
    traverse_leaf(root->right,ans);

    traverse_right(root->right,ans);

    for(auto i:ans)
    {
        cout<<i<<"   ";
    }

}

int main()
{
    Node* root = create_tree();

    cout<<"Boundary trvaersal "<<endl;
    boundary_traversal(root);
    cout<<endl;

    return 0;
}