
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

void right_view(Node* root , vector<int> &ans,int level)
{
    if(root==NULL)
    {
        return;
    }

    if(ans.size()==level)
    {
        ans.push_back(root->data);
    }

    right_view(root->right,ans,level+1);
    right_view(root->left,ans,level+1);

}

int main()
{
   Node* root = create_tree();
   vector<int> ans;
   cout<<"Right view of tree  "<<endl;
   right_view(root,ans,0);

   for(auto i:ans)
   {
        cout<<i<<"   ";
   } 

   return 0;
}