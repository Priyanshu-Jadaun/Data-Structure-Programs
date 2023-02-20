
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

Node* lca(Node* root,int x,int y)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data ==x || root->data==y)
        {
            return root;
        }
        else
        {
            Node* l = lca(root->left,x,y);
            Node* r = lca(root->right,x,y);
            if(l==NULL)
            {
                return r;

            }
            else if(r==NULL)
            {
                return l;
            }
            else
            {
                return root;
            }
        }
    }
}

int main()
{
    Node* root = NULL;
    root = create_tree(root);

    Node* temp = lca(root,3,4);
    cout<<"LCA "<<temp->data<<endl;

    return 0;
}