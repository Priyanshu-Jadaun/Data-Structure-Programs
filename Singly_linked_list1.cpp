
#include<map>
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
// bool check_circular(Node* head)
// {
//     if(head==NULL)
//     {
//         return true;
//     }
    
//     Node* temp = head;

//     do{
//         temp=temp->next;

//     }while(temp != NULL && temp != head);

    

//     if(temp==NULL)
//     {
//         return false;
//     }
//     if(temp==head)
//     {
//         return true;
//     }
// }

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

// bool detect_loop(Node* head)
// {
//     if(head == NULL)
//     {
//         return false;
//     }

//     map<Node* , bool> visited;

//     Node* temp =head;

//     while(temp!= NULL)
//     {
//         if(visited[temp]==true)
//         {
//             cout<<"Loop is present on  "<<temp->data<<endl;
//             return true;
//         }
//         visited[temp]=true;
//         temp=temp->next;
//     }

//     return false;
// }

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    // insertAthead(20,head);
    // insertAthead(30,head);
    // insertAthead(40,head);

    insertAttail(20,tail);
    insertAttail(30,tail);
    insertAttail(40,tail);
    insertAttail(50,tail);

    insertAtany(3,35,head,tail);
    print(head);
    cout<<"Head"<<head->data<<endl;

    cout<<endl;
    deleteAny(1,head,tail);
    print(head);
    cout<<"Head   "<<head->data<<endl;
    cout<<"Tail   "<<tail->data<<endl;

    //cout<<detect_loop(head)<<endl;
    //cout<<check_circular(head)<<endl;
    return 0;

}