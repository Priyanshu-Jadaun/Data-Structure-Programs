
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

Node* insert_bst(Node* root , int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(root->data >d)
    {
        root->left = insert_bst(root->left,d);
    }
    if(root->data <d)
    {
        root->right = insert_bst(root->right,d);
    }

    return root;

}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}


bool search(Node* root ,int d)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == d)
    {
        return true;
    }
    if(root->data > d)
    {
        return search(root->left,d);
    }
    if(root->data < d)
    {
        return search(root->right,d);
    }
}

bool search_it(Node* root , int d)
{
    if(root == NULL)
    {
        return false;
    }
    while(root != NULL)
    {
        if(root->data == d )
        {
            return true;
        }
        if( root->data > d)
        {
            root = root->left;
        }
        if(root->data < d)
        {
            root = root->right;
        }
    }
    return false;
}

int max_val(Node* root)
{
    if(root->right == NULL)
    {
        return root->data;
    }
    max_val(root->right);
}

int min_val(Node* root)
{
    if(root->left == NULL)
    {
        return root->data;
    }
    min_val(root->left);
}

int inorder_pre(Node* root , int d)
{
    Node* temp = root;
    int prede =0; 
    while(temp != NULL)
    {
        if(temp->data < d)
        {
            prede =temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return prede;
}

int inorder_succ(Node* root , int d)
{
    Node* temp = root;
    int succ = 0;
    while(temp != NULL)
    {
        if(temp->data < d)
        {
            temp = temp->left;
        }
        else
        {
            succ = temp->data;
            temp = temp->right;
        }
    }
    return succ;
}

int main()
{
    Node* root = NULL;
    int data;
    cout<<"Enter data "<<endl;
    
    int i=0;
    while(i==0)
    {
        cin>>data;
        root = insert_bst(root,data);
        cout<<"Want to enter data press 0"<<endl;
        cin>>i;
    }
    cout<<"Inorder "<<endl;
    inorder(root);
    cout<<endl;

    if(search(root,15))
    {
        cout<<"Found "<<endl;
    }
    else
    {
        cout<<"Not found "<<endl;
    }
    cout<<"Iterative "<<endl;
    if(search_it(root,20))
    {
        cout<<"Found "<<endl;
    }
    else
    {
        cout<<"Not found "<<endl;
    }

    cout<<"Maximum Value "<<max_val(root)<<endl;
    cout<<"Minimum Value "<<min_val(root)<<endl;

    cout<<"Predecessor "<<(root,15)<<endl;
    cout<<"Successor "<<(root,15)<<endl;
    return 0;

}

