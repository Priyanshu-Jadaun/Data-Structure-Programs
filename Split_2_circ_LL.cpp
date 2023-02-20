
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

int print(Node* &tail)
{
    Node* temp=tail;
    int count=0;
    do
    {
        cout<<temp->data<<endl;
        temp=temp->next;
        count++;
    }while(temp!=tail);
    cout<<endl;
    return count;
}

int main()
{
    Node* tail=NULL;
    insert(3,5,tail);
    insert(5,3,tail);
    insert(7,5,tail);
    insert(6,7,tail);
    insert(8,6,tail);
    insert(10,8,tail);
    insert(15,10,tail);

    insert(16,15,tail);
    int len = print(tail);

    Node* slow = tail;
    Node* fast = tail->next;
    while(fast->next != tail)
    {
        fast = fast->next;
        if(fast->next!= tail)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

    cout<<slow->data<<endl;
    cout<<fast->data<<endl;

    Node* head1 ;
    Node* head2 ;

    head1 = tail; 
    head2 = slow->next;

    slow->next = head1;
    fast->next = head2;
    cout<<endl;

    cout<<"1st circular ll "<<endl;
    print(head1);
    cout<<endl;

    cout<<"2nd circular ll "<<endl;
    print(head2);
    cout<<endl;

    return 0;
}