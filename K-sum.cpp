
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

void k_sum(Node* root,int &count,vector<int> ans,int sum)
{
    if(root==NULL)
    {
        return;
    }
    ans.push_back(root->data);

    k_sum(root->left,count,ans,sum);
    k_sum(root->right,count,ans,sum);

    int a=0;

    for(int i=ans.size()-1;i>=0;i--)
    {
        a = a + ans[i];
        if(a==sum)
        {
            count = count+1;
            break;
        }
    }
    
}

int main()
{
    Node* root = create_tree();
    vector<int> ans;
    int count=0;
    
    k_sum(root,count,ans,5);

    cout<<"Count  "<<count<<endl;

    return 0;
}