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
        int index =0;

        for(int i=0;i<size;i++)
        {
            Node* front_Node = q.front();
            q.pop();

            if(left_right)
            {
                index = i;
            }
            else
            {
                index = size-i-1;
            }
            ans[index] = front_Node->data;

            if(front_Node->left)
            {
                q.push(front_Node->left);
            }
            if(front_Node->right)
            {
                q.push(front_Node->right);
            }
        }
        left_right = !left_right;

        for(auto i:ans)
        {
            result.push_back(i);
        }

    }

    cout<<"Its here "<<endl;
    for(auto i : result)
    {
        cout<<i<<"  ";
    }
}

void left_side_traversal(Node* root , vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }

    ans.push_back(root->data);
    if(root->left)
        left_side_traversal(root->left,ans);

    else
        left_side_traversal(root->right,ans);
}

void leaf_node_traversal(Node* root , vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leaf_node_traversal(root->left,ans);
    leaf_node_traversal(root->right,ans);

}

void right_side_traversal(Node* root,vector<int> &ans)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }

    if(root->right)
        right_side_traversal(root->right,ans);

    else
        right_side_traversal(root->left,ans);
        
    ans.push_back(root->data);
}

void boundary_traversal(Node* root)
{
    vector<int > ans;
    ans.push_back(root->data);
    
    left_side_traversal(root->left,ans);
    
    leaf_node_traversal(root->left,ans);
    leaf_node_traversal(root->right,ans);
    
    right_side_traversal(root->right,ans);

    for(auto i:ans)
    {
        cout<<i<<"  ";
    }
}

void vertical_order_traversal(Node* root)
{
    map <int , map<int ,vector<int> > > ordered;
    queue <pair < Node* , pair<int,int> > > q;

    vector<int> ans;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty())
    {
        pair < Node* , pair<int,int> > temp = q.front();
        q.pop();

        Node* front_Node = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        ordered[hd][level].push_back(front_Node->data);

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,make_pair(hd-1,level+1)));
        }

        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,make_pair(hd+1,level+1)));
        }
    }

    for(auto i :ordered)
    {
        for(auto j :i.second)
        {
            for(auto k :j.second)
            {
                ans.push_back(k);
            }
        }
    }

    for(auto i :ans)
    {
        cout<<i<<"   ";
    }
}

void top_view(Node* root)
{
    map <int,int> ordered;
    queue <pair <Node*,int> > q;

    vector <int> ans;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();
        
        Node* front_Node = temp.first;
        int hd = temp.second;

        if(ordered.find(hd) == ordered.end())
        {
            ordered[hd] = front_Node->data;
        }

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,hd-1));
        }

        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,hd+1));
        }
    }

    for(auto i: ordered)
    {
        ans.push_back(i.second);
    }

    for(auto i : ans)
    {
        cout<<i<<"   ";
    }

}

void bottom_view(Node* root)
{
    map<int,int> visits;
    queue <pair<Node* ,int> > q;

    vector<int> ans;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node* ,int> temp = q.front();
        q.pop();

        Node* front_Node = temp.first;
        int hd = temp.second;

        visits[hd] = front_Node->data;

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,hd-1));
        }

        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,hd+1));
        }
    }

    for(auto i:visits)
    {
        ans.push_back(i.second);
    }
    for(auto i:ans)
    {
        cout<<i<<"   ";
    }

}

void left_view(Node* root)
{
    map<int,int> visit;
    vector<int> ans;

    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node* ,int> temp = q.front();
        q.pop();

        Node* front_Node = temp.first;
        int level = temp.second;

        if(visit.find(level) == visit.end())
        {
            visit[level] = front_Node->data;
        }

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,level+1));
        }

        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,level+1));
        }
    }

    for(auto i : visit)
    {
        ans.push_back(i.second);
    }
    for(auto j : ans)
    {
        cout<<j<<"    ";
    }
}

void right_view(Node* root)
{
    map<int,int> visit;
    queue<pair <Node* ,int> > q;

    q.push(make_pair(root,0));
    vector<int> ans;

    while(!q.empty())
    {
        pair <Node*,int> temp = q.front();
        q.pop();

        Node* front_Node = temp.first;
        int level = temp.second;

        visit[level] = front_Node->data;

        if(front_Node->left)
        {
            q.push(make_pair(front_Node->left,level+1));
        }
        if(front_Node->right)
        {
            q.push(make_pair(front_Node->right,level+1));
        }
    }
    for(auto i:visit)
    {
        ans.push_back(i.second);
    }
    for(auto i:ans)
    {
        cout<<i<<"  ";
    }
}

int main()
{
    Node* root = create_tree();
    cout<<"Zig Zag Traversal "<<endl;
    zig_zag_traversal(root);
    cout<<endl;

    cout<<"Boundary Traversal "<<endl;
    boundary_traversal(root);
    cout<<endl;

    cout<<"Vertical Order Traversal "<<endl;
    vertical_order_traversal(root);
    cout<<endl;

    cout<<"Top View "<<endl;
    top_view(root);
    cout<<endl;

    cout<<"Bottom View "<<endl;
    bottom_view(root);
    cout<<endl;

    cout<<"Left View "<<endl;
    left_view(root);
    cout<<endl;

    cout<<"Right View "<<endl;
    right_view(root);
    cout<<endl;
    
    return 0;
}