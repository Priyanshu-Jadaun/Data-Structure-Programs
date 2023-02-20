
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

    ~Node()
    {
        if(this->next!=NULL)
        {
            this->next=NULL;
            delete next;
        }
        delete next;
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

void deleteAny(int position,Node* &head,Node* &tail)
{
    if(position==1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next == NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            tail = prev;
            delete curr;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        
    }
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
}
int count(Node* head)
{
    int cnt=0,even=0,odd=0;
    Node* temp = head;
    while(temp != NULL)
    {
        cnt++;
        if(temp->data%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        temp = temp->next;
    }
    cout<<"\n Nodes containing even information "<<even<<endl;
    cout<<"Nodes containing odd information "<<odd<<endl;

    return cnt;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAthead(20,head);
    insertAthead(30,head);
    insertAthead(40,head);
    insertAttail(50,tail);
    insertAtany(3,35,head,tail);
    cout<<"After insertion "<<endl;
    print(head);
    deleteAny(1,head,tail);
    cout<<"\n After Deletion "<<endl;
    print(head);
    cout<<"\n Total Nodes in Linked List are "<<count(head)<<endl;
    return 0;

}