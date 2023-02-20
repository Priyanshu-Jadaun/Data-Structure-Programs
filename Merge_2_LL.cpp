
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

Node* solve(Node* first , Node* second)
{
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }
    else
    {
        Node* curr1 = first;
        Node* curr2 = second;
        Node* next1 = first->next;
        Node* next2 = curr2->next;

        while(curr2!= NULL && next1 != NULL)
        {
            if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
            {
                curr1-> next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr1->next;
                curr2 = next2;
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;

            }
        }
        if(curr2 != NULL)
        {
            curr1->next = curr2;
        }
    }
    return first;
}

Node* merge(Node* first , Node* second)
{
    if(first == NULL)
    {
        return second;
    }
    if(second == NULL)
    {
        return first;
    }

    if(first->data <= second->data)
    {
        return solve(first,second);
    }
    else
    {
        return solve(second,first);
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail1 = node1;

    Node* node2 = new Node(2);
    Node* head2 = node2;
    Node* tail2 = node2;

    insertAttail(3,tail1);
    insertAttail(5,tail1);
    insertAttail(5,tail1);

    insertAttail(4,tail2);
    insertAttail(6,tail2);
    insertAttail(8,tail2);

    cout<<"1st LL "<<endl;
    print(head1);
   
    cout<<"2nd LL "<<endl;
    print(head2);

    Node* temp = merge(head1,head2);
    cout<<"After merging "<<endl;
    print(temp);
    cout<<endl;

    return 0;

}