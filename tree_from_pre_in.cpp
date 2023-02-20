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

int find_position(int in[],int element,int size)
{
    for(int i=0;i<size;i++)
    {
        if(in[i]==element)
        {
            return i;
        }
    }
}

Node* solve(int in[],int pre[],int size,int &index,int in_start,int in_end)
{
    if((index >= size) || (in_start > in_end))
    {
        return NULL;
    }

    int element = pre[index];
    index = index+1;
    int pos = find_position(in,element,size);

    Node* root = new Node(element);

    root->left = solve(in,pre,size,index ,in_start,pos-1);
    root->right = solve(in,pre,size,index,pos+1,in_end);

    return root;
}

void traverse(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    traverse(root->left);
    traverse(root->right);
    cout<<root->data<<"   ";
}

int main()
{
    int in[]={1,6,8,7};
    int pre[]={1,6,7,8};

    // 8 7 6 1 ( POST ORDER )

    int index=0;
    Node* root = solve(in,pre,4,index,0,3);
    traverse(root);

    return 0;
}