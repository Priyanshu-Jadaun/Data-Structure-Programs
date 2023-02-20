
#include<queue>
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;
    Node* child;
    Node* sibling;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->child =  NULL;
        this->sibling= NULL;
    }
};

Node* create(Node* root)
{
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;

    if(data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter data for child "<<data<<endl;
    root->left = create(root->left);

    cout<<"Enter  data for  sibling "<<data<<endl;
    root->right = create(root->right);

    return root;

}

Node* convert_to_binary(Node* root)
{
    Node* temp = NULL;
    temp->data = root->data;

}

void level_order_traversal(Node* root)
{
    queue<Node* > q;
    q.push(root);
    int visited=0;
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

void level_order_traversal_space(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
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

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {   
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    Node* root = create(NULL);
    
    cout<<"Level order traversal "<<endl;
    level_order_traversal(root);

    cout<<"\n Level order traversal with spaces "<<endl;
    level_order_traversal_space(root);

    cout<<"\n Inorder traversal "<<endl;
    inorder(root);

    cout<<"\n Preorder traversal "<<endl;
    preorder(root);

    cout<<"\n Postorder traversal "<<endl;
    postorder(root);

    return 0;

}