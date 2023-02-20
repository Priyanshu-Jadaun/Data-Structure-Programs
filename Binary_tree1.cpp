
#include<queue>
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

Node* build_tree(Node* root)
{
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    if(data != -1)
    {
        root = new Node(data);
        cout<<"Enter data for left "<<root->data<<endl;
        root->left = build_tree(NULL);
        cout<<"Enter data for right "<<root->data<<endl;
        root->right = build_tree(NULL);
    }

    return root;
}

void traverse(Node* root)
{
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp==NULL )
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
    cout<<endl;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void build_traversal(Node* &root)
{
    int data;
    queue<Node*> q;
    cout<<"Enter data for root node"<<endl;
    cin>>data;

    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        int left_data;
        cout<<"Enter data for left of "<<temp->data<<endl;
        cin>>left_data;
        if(left_data != -1)
        {
            temp->left = new Node(left_data);
            q.push(temp->left);
        }

        int right_data;
        cout<<"Enter data for right of "<<temp->data<<endl;
        cin>>right_data;
        if(right_data != -1)
        {
            temp->right = new Node(right_data);
            q.push(temp->right);
        }

    }
    
}

void count_leaf(Node* root,int *count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        *count = *count+1;
        cout<<root->data<<endl;
    }

    if(root->left!=NULL)
    {
        count_leaf(root->left,count);
    }
    if(root->right !=NULL)
    {
        count_leaf(root->right,count);
    }        
}

int count_leaf(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int n1 = 0;int n2=0;
    if(root->left!=NULL)
    {
        
        n1 = count_leaf(root->left);
    }
    if(root->right !=NULL)
    {
        
        n2 = count_leaf(root->right);
    }        
    return (n1+n2);
}

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (max(height(root->left),height(root->right))+1);
    }
}

int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int d1 = diameter(root->left);
        int d2 = diameter(root->right);
        int d3 = height(root->left) + height(root->right)+1;

        return max(d1,max(d2,d3));
    }
}

pair<int,int> diameter_optimised(Node* root)
{
    if(root==NULL)
    {
        pair<int,int> p = make_pair(0,0);
        
        return p;
    }
    else
    {
        pair<int,int> left = diameter_optimised(root->left);
        pair<int,int> right = diameter_optimised(root->right);

        int d1 = left.first;
        int d2 = right.first;
        int d3 = left.second + right.second +1;

        int ans = max(d1,max(d2,d3));

        pair<int,int> f = make_pair(ans,(max(left.second,right.second)+1));

        return f;
    }
}

bool is_balanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        bool left = is_balanced(root->left);
        bool right = is_balanced(root->right);
        bool ans;
        if(abs(height(root->left)-height(root->right))<=1)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }

        if(left && right && ans)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

pair<bool,int> is_balanced_optimised(Node* root)
{
    if(root==NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    else
    {
        pair<bool,int> left = is_balanced_optimised(root->left);
        pair<bool,int> right = is_balanced_optimised(root->right);
        bool a;
        if(abs(left.second - right.second)<=1)
        {
            a = true;
        }
        else
        {
            a = false;
        }
        pair<bool , int> ans ;
        if(left.first && right.first && a)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }

        ans.second = max(left.second , right.second )+1;
        return ans;
    }
}

bool is_identical(Node* root1 , Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else
    {
        bool left = is_identical(root1->left,root2->left);
        bool right = is_identical(root1->right,root2->right);
        bool value = (root1->data == root2->data);

        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

pair<bool,int> is_sum_tree(Node* root)
{
    if(root==NULL)
    {
        pair<bool , int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = is_sum_tree(root->left);
    pair<bool,int> right = is_sum_tree(root->right);

    bool value = (root->data == (left.second+right.second));

    ans pair;
    if(left.first && right.first && value)
    {
        return true;
    }
}

vector<int> zig_zag_traversal(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }

    else
    {
        bool left_to_right = true;
        queue<Node* > q;

        q.push(root);

        while(!q.empty())
        {


int main()
{
    Node* root = NULL;
    //traverse(temp);
    // cout<<"INORDER"<<endl;
    // inorder(temp);
    // cout<<"PREORDER"<<endl;
    // preorder(temp);
    // cout<<"POSTORDER"<<endl;
    // postorder(temp);
    // cout<<endl;

    build_traversal(root);
    cout<<"Tree is "<<endl;
    traverse(root);

    // int count=0;
    // count_leaf(root,&count);
    // cout<<"Leaf node"<<count<<endl;

    // cout<<"Leaf node"<<count_leaf(root)<<endl;

    // cout<<"Height of tree is "<<height(root)<<endl;
 
    // cout<<"Diameter of tree is "<<diameter(root)<<endl;

    // pair<int,int> ans = diameter_optimised(root);
    // cout<<"Optimised diameter of tree is "<<ans.first<<endl;
    // cout<<"Optimised height of tree is "<<ans.second<<endl;

    // cout<<"Balanced or not "<<is_balanced(root)<<endl;

    // pair<bool,int> check = is_balanced_optimised(root);
    // cout<<"Balanced or not "<<check.first<<endl;
    // cout<<"Height of tree "<<check.second<<endl;

    Node* root1 = NULL;
    build_traversal(root1);
    cout<<"Tree is "<<endl;
    traverse(root1);

    cout<<"They are identical or not "<<endl;
    if(is_identical(root,root1))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


    return 0;
}