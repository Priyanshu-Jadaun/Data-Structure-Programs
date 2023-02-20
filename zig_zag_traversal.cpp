
#include<queue>
#include<vector>
#include<cstdlib>
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

void zig_zag_traversal(Node* root)
{
    vector<int> result;
    
    bool left_right = true;
    
    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        int index=0;

        for(int i=0;i<size;i++)
        {
            Node* temp = q.front();
            q.pop();
            
            if(left_right)
            {
                index = i;
            }
            else
            {
                index = size-i-1;
            }

            ans[index] = temp->data;
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }

        }
        left_right = !left_right;

        for(auto i:ans)
        {
            result.push_back(i);
        }

    }

    cout<<"Zig-Zag-Traversal "<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<"   ";
    }
    cout<<endl;

}

int main()
{

    Node* root = create_tree();
    zig_zag_traversal(root);

    return 0;
}