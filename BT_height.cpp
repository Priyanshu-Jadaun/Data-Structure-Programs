
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

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return (max(height(root->left),height(root->right))+1);

}

int main()
{
    Node* temp = create_tree(NULL);
    traversal(temp);
    cout<<endl;

    cout<<"Height of BT is "<<height(temp)<<endl;

    return 0;    
}
