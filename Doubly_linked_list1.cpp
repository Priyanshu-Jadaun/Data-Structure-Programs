#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        if(this->next!=NULL)
        {
            this->next=NULL;
            this->prev=NULL;
        }
    }
};

void insertathead(int data,Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail=temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
   
}

void insertattail(int data,Node* &tail)
{
    if(tail==NULL)
    {
        Node* temp = new Node(data);
        tail=temp;
    }

    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertatany(int data,int position,Node* &head,Node* &tail)
{
    if(position==1)
    {
        insertathead(data,head,tail);
        return;
    }

    Node* temp = head;
    Node* nodetoinsert = new Node(data);
    int count=1;
    while(count<(position-1))
    {
        temp= temp->next;
        count++;
    }

    if(temp->next==NULL)
    {
        insertattail(data,tail);
        return;
    }

    nodetoinsert->next = temp->next;
    nodetoinsert->prev = temp;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;

}

void deletion(int position,Node* &head,Node* &tail)
{
    if(position==1)
    {
        Node* temp = head;
        head=head->next;
        temp->next = NULL;
        head->prev = NULL;

        delete temp;
    }
    else
    {
        
        int count =1;
        Node* temp=NULL;
        Node* curr = head;

        while(count<position)
        {
            temp = curr;
            curr= curr->next;
            count++;
        }

        if(curr->next==NULL)
        {
            temp->next=NULL;
            curr->prev = NULL;
            tail= temp;
            delete curr;
        }
        else
        {
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->prev=NULL;
            curr->next=NULL;
            delete curr; 
        }
    }
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    } 

}

int main()
{

    Node* head = NULL;
    Node* tail = NULL;

    insertathead(15,head,tail);
    insertathead(10,head,tail);
    insertathead(5,head,tail);

    insertattail(25,tail);
    insertattail(30,tail);
    insertattail(35,tail);

    insertatany(3,1,head,tail);
    insertatany(7,3,head,tail);
    insertatany(50,9,head,tail);
    print(head);
    cout<<endl;

    deletion(1,head,tail);
    deletion(8,head,tail);
    deletion(4,head,tail);

    print(head);
    cout<<endl;
    cout<<"Head  "<<head->data<<endl;
    cout<<"Tail  "<<tail->data<<endl;

    return 0;
}