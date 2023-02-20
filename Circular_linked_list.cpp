
#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    
};

void insert(int data,int element,Node* &tail)
{
    if(tail==NULL)
    {
        Node* temp = new Node(data);
        temp->next=temp;
        tail=temp;
    }
    else
    {
        Node* temp = new Node(data);
        Node* curr = tail;
        while(curr->data != element)
        {
            curr=curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail)
{
    Node* temp=tail;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;

}

int main()
{
    Node* tail=NULL;
    insert(3,5,tail);
    insert(5,3,tail);
    insert(7,5,tail);
    insert(6,5,tail);
    
    print(tail);
    cout<<"Tail at "<<tail->data<<endl;


    return 0;
}