#include<iostream>
#include<queue>
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
        this->right = NULL;
        this->left = NULL;
    }
};

Node* create(Node* root)
{
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter left data for "<<data<<endl;
    root->left = create(root->left);

    cout<<"Enter right data for  "<<data<<endl;
    root->right = create(root->right);

    return root;
}

void level_order(Node* root)
{
    queue<Node*>q;

    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}

void inorder(Node* root)
{
    if(root== NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{

    Node* root = NULL;
    Node* temp = create(root);
    level_order(temp);
    cout<<endl;

    return 0;
}