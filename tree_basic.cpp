
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

void count_leaf(Node* root , int *count)
{
    if(root==NULL)
    {
        return;
    }

    count_leaf(root->left, count);
    if(root->left==NULL && root->right == NULL)
    {
        *count = *count+1;
    }
    count_leaf(root->right, count);
}

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (max(left,right)+1);
}

int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left = diameter(root->left);
    int right = diameter(root->right);

    int curr = height(root->left)+height(root->right)+1;

    return max(left,max(right,curr));

}

bool balanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }

    bool left = balanced(root->left);
    if(left == false)
    {
        return false;
    }
    bool right = balanced(root->right);

    bool curr = (abs(height(root->left)-height(root->right))) <= 1;

    if(left && right && curr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool is_identical(Node* root1 , Node* root2)
{
    

    if(root1==NULL && root2 ==NULL)
    {
        return true;
    }
    if(root1==NULL && root2!=NULL)
    {
        return false;
    }
    if(root2==NULL && root1 != NULL)
    {
        return false;
    }
    bool left = is_identical(root1->left,root2->left);
    if(!left)
    {
        return false;
    }
    bool right = is_identical(root1->right,root2->right);

    bool curr = root1->data == root2->data;

    if(left && right && curr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

pair<int,bool> is_sum(Node* root)
{
    if(root == NULL)
    {
        pair<int ,bool> p = make_pair(0,true);
        return p;
    }

    if(root->left==NULL && root->right==NULL)
    {
        pair<int ,bool> p = make_pair(root->data,true);
        return p;
    }

    pair<int,bool> left_ans = is_sum(root->left);
    pair<int,bool> right_ans = is_sum(root->right);

    pair<int ,bool> ans;

    bool left = left_ans.second;
    bool right = right_ans.second;

    bool val = (root->data == (left_ans.first + right_ans.first));

    if(left && right && val)
    {
        ans.second = true;
        ans.first = 2*(root->data);
    }
    else
    {
        ans.second = false;
        ans.first = root->data + left_ans.first + right_ans.first;
    }

    return ans;
}

int main()
{
    Node* root1 = create_tree();
    cout<<"Enter 2nd tree "<<endl;
    Node* root2 = create_tree();

    cout<<"INORDER traversal "<<endl;
    inorder(root1);cout<<endl;
    cout<<"PREORDER traversal "<<endl;
    preorder(root1);cout<<endl;
    cout<<"POSTORDER traversal "<<endl;
    postorder(root1);cout<<endl;
    int count=0;
    count_leaf(root1,&count);
    cout<<"Total Leaf Nodes in  tree : "<<count<<endl;
    cout<<"Height of binary tree : "<<height(root1)<<endl;
    cout<<"Diameter of binary tree : "<<diameter(root1)<<endl;

    if(balanced(root1))
    {
        cout<<"Tree is balanced "<<endl;
    }
    else
    {
        cout<<"Tree is not balanced"<<endl;
    }

    if(is_identical(root1,root2))
    {
        cout<<"Both Trees are identical "<<endl;
    }
    else
    {
        cout<<"Trees are not identical "<<endl;
    }

    pair<int ,bool> ans = is_sum(root1);
    if((ans.second))
    {
        cout<<"Its sum tree "<<endl;
    }
    else
    {
        cout<<"Not sum tree "<<endl;
    }

    return 0;

}
