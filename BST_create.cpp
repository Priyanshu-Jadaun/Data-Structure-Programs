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

Node* create_bst(Node* root , int element)
{
    if(root == NULL)
    {
        Node* temp = new Node(element);
        return temp;
    }   
    if(root->data > element)
    {
        root->left = create_bst(root->left , element);
    }
    else
    {
        root->right = create_bst(root->right , element);
    }
    return root;
}

void traversal_in(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    traversal_in(root->left);
    cout<<root->data<<"   ";
    traversal_in(root->right);
}
bool find_bst(Node* root, int d)
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
        return find_bst(root->left,d);
    }
    else
    {
        return find_bst(root->right,d);
    }
}

bool find_bst_it(Node* root,int d)
{
    while(root != NULL)
    {
        if(root->data == d)
        {
            return true;
        }

        if(root->data >d)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}

int min_val(Node* root)
{
    if(root->left == NULL)
    {
        return root->data;
    }

    min_val(root->left);

}

int max_val(Node* root)
{
    if(root->right == NULL)
    {
        return root->data;
    }

    max_val(root->right);
}

int main()
{
    int data;
    cin>>data;
    Node* root = NULL;
    while(data!=-1)
    {
        root = create_bst(root,data);
        cin>>data;
    }
    cout<<"INOREDER TRAVERSAL "<<endl;
    traversal_in(root);
    cout<<endl;

    int search =0;
    cout<<"Enter element to search in bst"<<endl;
    cin>>search;

    if(find_bst(root,search))
    {
        cout<<"YES found ";
    }
    else
    {
        cout<<"NOT  Present ";
    }
    cout<<endl;

    if(find_bst_it(root,search))
    {
        cout<<"YES found ";
    }
    else
    {
        cout<<"NOT  Present ";
    }
    cout<<endl;

    cout<<"Maximum Value in BST "<<max_val(root)<<endl;
    cout<<"Minimum value in BST "<<min_val(root)<<endl;
    
    return 0;

}