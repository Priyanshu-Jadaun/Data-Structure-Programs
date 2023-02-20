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

void level_order(Node* root)
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

int main()
{
    Node* root = NULL;
    root = create_tree(root);

    level_order(root);
    cout<<endl;

    return 0;
}