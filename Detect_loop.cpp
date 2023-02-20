
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
bool check_loop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node* , bool> visited;

    Node* temp =head;

    while(temp!= NULL)
    {
        if(visited[temp]==true)
        {
            cout<<"Loop is present on  "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }

    return false;
}

Node* detect_loop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;

    while(slow != NULL &&  fast!= NULL)
    {
        
        fast = fast->next;
        if(fast!=NULL)
        {
            
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow)
        {
            cout<<"Cycle is present at "<<fast->data<<endl;
            return slow;
        }

    }
    return NULL;
}

Node* start_loop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* intersection = detect_loop(head);

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection->next;
    }
    return slow;
}

void remove(Node* head)
{
    if(head == NULL)
    {
        return ;
    }

    Node* intersection = start_loop(head);
    Node* temp = intersection;
    while(temp->next != intersection)
    {
        temp = temp->next;

    }

    temp ->next = NULL;
}

int main()
{
    Node* tail=NULL;
    insert(3,5,tail);
    insert(5,3,tail);
    insert(7,5,tail);
    insert(6,5,tail);
    insert(8,6,tail);
    //insert(9,8,tail);
    
    print(tail);
    cout<<"Tail at "<<tail->data<<endl;
    cout<<detect_loop(tail)<<endl;

    //Node* temp = start_loop(tail);
    remove(tail);
    cout<<check_loop(tail)<<endl;
    return 0;
}

