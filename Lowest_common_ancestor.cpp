
#include<climits>
#include<map>
#include<queue>
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

Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data == a || root->data == b)
    {
        return root;
    }

    Node* left_ans = lca(root->left,a,b);
    Node* right_ans = lca(root->right,a,b);
    
    if(left_ans!=NULL && right_ans==NULL)
    {
        return left_ans;
    }
    if(right_ans!=NULL && left_ans==NULL)
    {
        return right_ans;
    }
    if(left_ans!=NULL && right_ans!=NULL)
    {
        return root;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    Node* root = create_tree();
   
    Node* temp = lca(root,3,8);
    cout<<temp->data<<endl;

    return 0;
}