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
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

//ITERATIVE SOLUTION

// void reverse(Node* &head)
// {
//     if(head == NULL || head->next == NULL)
//     {
//         return ;
//     }
//     else
//     {
//         Node* prev = NULL;
//         Node* curr = head;
//         Node* frwrd ;

//         while(curr!= NULL)
//         {
//             frwrd=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=frwrd;
//         }
//         head=prev;
//         return;
//     }
// }

//RECURSIVE SOLUTION

void reverse(Node* &head,Node* curr,Node* prev)
{
    if(curr==NULL)
    {
        head=prev;
        return ;
    }
    
    Node* frwrd = curr->next;
    curr->next=prev;
    reverse(head,frwrd,curr);

    return;
}

// RECURSIVE ANOTHER WAY 
Node* reverse(Node* &head)
{
    if(head==NULL|| head->next == NULL)
    {
        return head;
    }
    else
    {
        Node* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    insertAttail(20,tail);
    insertAttail(30,tail);
    insertAttail(40,tail);
    insertAttail(50,tail);

    insertAtany(3,35,head,tail);
    cout<<endl;
    print(head);
    cout<<"Head   "<<head->data<<endl;
    cout<<"Tail   "<<tail->data<<endl;

    //reverse(head,head,NULL);
    Node* temp=reverse(head);
    head=temp;
    print(head);
    cout<<"Head   "<<head->data<<endl;
    cout<<endl;

    return 0;

}