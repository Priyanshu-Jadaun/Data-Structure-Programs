
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
        this->left = NULL;
        this->right = NULL;

    }
};

Node* build_tree_level_order(Node* root)
{
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;

    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int left_data;
        cout<<"Enter data for left of "<<temp->data<<endl;
        cin>>left_data;

        if(left_data==-1)
        {
            temp->left = NULL;
        }
        else
        {
            temp->left = new Node(left_data);
            q.push(temp->left);

        }

        int right_data;
        cout<<"Enter data for right of "<<temp->data<<endl;
        cin>>right_data;

        if(right_data==-1)
        {
            temp->right = NULL;
        }
        else
        {
            temp->right = new Node(right_data);
            q.push(temp->right);

        }

    }
    return root;
}

void level_order_traversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp  = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
    }
}

int main()
{
    Node* temp = build_tree_level_order(NULL);
    level_order_traversal(temp);

    cout<<endl;
    return 0;   
}