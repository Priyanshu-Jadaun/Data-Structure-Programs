
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

void deleteAny(int position,Node* &head,Node* &tail){
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
void remove_dup_sorted(Node* &head , Node* &tail)
{
    if(head==NULL)
    {
        cout<<"List is empty "<<endl;
        return ;
    }
    else
    {
        Node* curr= head;
        while(curr!= NULL)
        {
            if(curr->next != NULL && curr->data == curr->next->data)
            {
                if(curr!= tail && curr->data == tail->data)
                {
                    tail = curr;
                }
                Node* next_next = curr->next->next;
                Node* delete_node = curr->next;
                delete_node->next = NULL;
                delete(delete_node);
                curr->next = next_next;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"   ";
        temp = temp->next;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAttail(20,tail);
    insertAttail(20,tail);
    insertAttail(30,tail);
    insertAttail(40,tail);
    insertAttail(40,tail);
    insertAttail(40,tail);
    insertAttail(50,tail);
    insertAttail(50,tail);
    insertAtany(5,35,head,tail);
    cout<<endl;
    cout<<"Linked List is "<<endl;print(head);
    remove_dup_sorted(head,tail);
    cout<<"\n After Removing Duplicates "<<endl;print(head);
    return 0;
}