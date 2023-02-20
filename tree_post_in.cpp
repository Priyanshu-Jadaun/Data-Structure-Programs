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

int find_pos(int in[] ,int element)
{
    for(int i=0;i<4;i++)
    {
        if(in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node* tree_post_in(int post[],int in[],int *index,int size,int in_start,int in_end)
{
    if(index <0 || ( in_start>in_end))
    {
        return NULL;
    }

    int element = in[*index];
    *index = *index-1;
    Node* root = new Node(element);
    int pos = find_pos(in,element);

    root->right = tree_post_in(post,in,index,size,pos+1,in_end);
    root->left = tree_post_in(post,in,index,size,in_start,pos-1);
    
    return root;
}

// INORDER TRAVERSAL
void traverse(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    traverse(root->left);
    cout<<root->data<<"   ";
    traverse(root->right);
}

int main()
{
    int post[4] = {8,7,6,1};
    int in[4] = {1,6,8,7};
    // PRE (1,6,7,8)

    int index =0;
    Node* root = tree_post_in(post,in,&index,4,0,3);
    traverse(root);
    cout<<endl;

    return 0;
}