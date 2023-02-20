
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

void sum_longest_blood_line(Node* root,int &max_level,int &max_sum ,int level ,int sum)
{
    if(root==NULL)
    {
        if(level>max_level)
        {
            max_sum = sum;
            max_level = level;
        }
        else if(level == max_level)
        {
            max_sum = max(max_sum,sum);
        }
        return;
    }

    // if(root->left==NULL && root->right==NULL)
    // {
    //     sum = sum + root->data;
    //     level = level+1;

    //     if(level>max_level)
    //     {
    //         max_sum = sum;
    //         max_level = level;
    //     }
    //     else if(level == max_level)
    //     {
    //         max_sum = max(max_sum,sum);
    //     }
    //     return;
    // }

    sum = sum + root->data;
    cout<<root->data<<endl;

    sum_longest_blood_line(root->left,max_level,max_sum,level+1,sum);
    sum_longest_blood_line(root->right,max_level,max_sum,level+1,sum);
}
int main()
{
    Node* root = create_tree();
    int max_level = INT_MIN;
    int max_sum = INT_MIN;

    sum_longest_blood_line(root,max_level,max_sum,0,0);
    cout<<"MAX_LEVEL   "<<max_level<<endl;
    cout<<"MAX_SUM    "<<max_sum<<endl;

    return 0;
}