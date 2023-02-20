
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

void bottom_view(Node* root)
{
    map<int,int> visit;
    vector<int> ans;
    queue <pair <Node*, int > > q;
    q.push(make_pair(root , 0));

    while(!q.empty())
    {
        pair<Node* , int > p;
        p = q.front();
        q.pop();

        int hd = p.second;
        Node* front_Node = p.first;

        visit[hd] = front_Node->data;

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,hd-1));
        }

        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,hd+1));
        }
    }

    for(auto i:visit)
    {
        ans.push_back(i.second);
    }

    for(auto i:ans)
    {
        cout<<i<<endl;
    }
}
int main()
{
    Node* root = create_tree();
    cout<<"Bottom View "<<endl;
    bottom_view(root);
    cout<<endl;

    return 0;

}