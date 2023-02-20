
#include<map>
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

void vertical_order_traversal(Node* root)
{
    vector<int> ans;
    map<int,map<int,vector<int> > > nodes;

    queue <pair<Node* , pair<int,int> > > q;
    
    q.push(make_pair(root , make_pair(0,0)));

    while(!q.empty())
    {
        pair <Node* , pair<int,int > > temp = q.front();
        Node* front_Node = temp.first;
        q.pop();

        int lvl = temp.second.second;
        int hd = temp.second.first;

        nodes[hd][lvl].push_back(front_Node->data);

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,make_pair(hd-1,lvl+1)));
        }
        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i : nodes)
    {
        for(auto j : i.second)
        {
            for(auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    cout<<"Traversal is "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"   ";
    }
}

int main()
{
    Node* root = create_tree();
    
    cout<<"Vertical Order Traversal "<<endl;
    vertical_order_traversal(root);
    cout<<endl;

    return 0;
    
} 
