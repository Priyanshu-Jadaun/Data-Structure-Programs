
#include<iostream>
#include<vector>
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

vector<int> All_K_Sum(Node* root , int k , int &count, vector<int> &v)
{
    v.push_back(root->data);
    All_K_Sum(root->left , k , &count, v)
}


int main()
{
    Node* root = NULL;
    root = create_tree(root);

    vector<int> v;

    return 0;
}