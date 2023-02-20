
#include<queue>
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
        this->right = NULL;
        this->left = NULL;
    }

};

Node* create_tree(Node* root)
{
    queue<Node*> q;
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;

    if(data != -1)
    {
        root = new Node(data);
        q.push(root);
    }
    else
    {
        return NULL;
    }

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int left_data;
        cout<<"Enter data for left of "<<temp->data<<endl;
        cin>>left_data;
        if(left_data != -1)
        {
            temp->left = new Node(left_data);
            q.push(temp->left);
        }

        int right_data;
        cout<<"Enter data for right of "<<temp->data<<endl;
        cin>>right_data;
        if(right_data != -1)
        {
            temp->right = new Node(right_data);
            q.push(temp->right);
        }

    }
    return root;
}

void traversal(Node* root)
{
    queue<Node* >q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    cout<<endl;
}

void count_leaf(Node* root,int &count)
{
    if(root== NULL)
    {
        return;
    }
    if(root->left==NULL && root->right == NULL)
    {
        count++;
    }
    count_leaf(root->left,count);
    count_leaf(root->right,count);
    
}

int main()
{
    Node* temp = create_tree(NULL);
    traversal(temp);
    int count=0;
    count_leaf(temp,count);
    cout<<count<<endl;
    return 0;
}