
#include<vector>
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAthead(int data,Node* &head)
{
    Node* temp= new Node(data);
    temp->next = head;
    head=temp;
}
void insertAttail(int data,Node* &tail)
{
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtany(int position,int data,Node* &head,Node* &tail)
{
    if(position==1)
    {
        insertAthead(data,head);
        return;
    }
    Node* temp=head;
    Node* nodetoinsert = new Node(data);
    int count=1;
    while(count<(position-1))
    {
        temp= temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertAttail(data,tail);
        return;
    }
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
bool Is_pallindrome(vector<int> arr)
{
    int n = arr.size();
    int i=0;
    int e=n-1;
    while(i<=e)
    {
        if(arr[i]!=arr[e])
        {
            return false;
        }
        i++; 
        e--;
    }
    return true;
}
bool check_pallindrome(Node* head)
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        vector<int> arr;
        Node* temp =head;
        while(temp!= NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return Is_pallindrome(arr);
    }
}
Node* getmiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAttail(20,tail);
    insertAttail(30,tail);
    insertAttail(20,tail);
    insertAttail(10,tail);
    print(head);
    if(check_pallindrome(head))
    {
        cout<<"Pallindrome"<<endl;
    }
    else
    {
        cout<<"Not Pallindrome"<<endl;
    }
    Node* temp = getmiddle(head);
    cout<<"Middle Element"<<temp->data<<endl;
    return 0;
}