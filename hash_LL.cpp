#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        data = data;
        next = NULL;
    }
};

void ins_end(Node* &head, int data)
{
    if(head == NULL)
    {
        Node* head = new Node(data);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* ins = new Node(data);
    temp->next = ins;
    return;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    
}

int main()
{
    Node* arr[15];
    for(int i=0;i<5;i++)
    {
        arr[i] = NULL;
    }
    int x;
    int r;
    for(int i=0;i<5;i++)
    {
        cin>>x;
        r = x % 10;
        ins_end(arr[r],x);
    }
    for(int i=0;i<15;i++)
    {
        print(arr[i]);
    }
    return 0;
}