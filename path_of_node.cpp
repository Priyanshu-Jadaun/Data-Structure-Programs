
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

bool path_node(Node* root,int data,vector<int>&ans)
{
    if(root==NULL)
    {
        return false;
    }   

    if(root->data ==data)
    {
        ans.push_back(root->data);
        return true;
    }

    ans.push_back(root->data);

    bool left_ans = path_node(root->left,data,ans);
    bool right_ans = path_node(root->right,data,ans);

    if(left_ans || right_ans)
    {
        return true;
    }
    else
    {
        ans.pop_back();
        return false;
    }
}

int main()
{
    Node* root = create_tree();
    vector<int> ans;

    path_node(root,8,ans);
    cout<<"Path "<<endl;
    for(auto i:ans)
    {
        cout<<i<<endl;
    }
    
    return 0;
}