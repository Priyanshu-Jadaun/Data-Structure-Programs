
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
    tail->next=NULL;
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

// void remove_unsort(Node* &head)
// {
//     if(head == NULL)
//     {
//         return ;
//     }
//     else
//     {
//         Node* curr = head;
//         while( curr!= NULL )
//         {
           
//             Node* temp = curr;
//             Node* dup;
//              while(temp->next != NULL )
//             {
                
//                 if(curr->data == temp->next->data)
//                 {
//                     dup = temp->next;
//                     temp->next= dup->next;
                   
//                     dup->next = NULL;
//                     delete (dup);
                    
//                 }
//                 else
//                 {
//                     temp = temp->next;
//                 }
//             }

//             curr= curr->next;
//         }
//     }
// }

void remove_unsort(Node* &head)  //USING MAP
{
    if(head==NULL)
    {
        return ;
    }
    else
    {
        map<int,bool> visited;
        visited[head->data] =true; 
        Node* temp = head->next;
        Node* prevs=head;
        while(temp!= NULL)
        {
           
            if(visited[temp->data]==true)
            {
                
                prevs->next = temp->next;
                delete(temp);
                temp = prevs->next;
            }
            else
            {
                visited[temp->data]=true;
                prevs = temp;
                temp= temp->next;

            }
            
        }
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

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    // insertAttail(2,tail);
    // insertAttail(5,tail);
    // insertAttail(3,tail);
    // insertAttail(2,tail);
    // insertAttail(5,tail);
  
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

    print(head);
    cout<<"Head   "<<head->data<<endl;
    cout<<"Tail   "<<tail->data<<endl;
    
    remove_unsort(head);
    print(head);
    //cout<<"Head   "<<head->data<<endl;
    //cout<<"Tail   "<<tail->data<<endl;
    
    return 0;

}