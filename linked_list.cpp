
#include<iostream>
using namespace std;

class node
{
    public:

    int data;
    node* next;

    node(int data) // CONSTRUCTOR
    {
        this->data = data;
        this->next = NULL;

    }

    ~node()
    {
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }

};

void inserthead(node* &head , node* &tail , int data)
{
    
    if(head==NULL)
    {
        node* temp =new node(data);
        head = temp;
        tail=temp;

    }

    else
    {
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

}

void print(node* &head, node* &tail)
{

    if(head==NULL)
    {
        cout<<"No linked list exist "<<endl;
    }    
    else
    {
         node* temp = head;

        while(temp != NULL)
        {
            cout<<temp->data<<endl;
             temp = temp->next;

        }

        cout<<"Head is at : "<<head->data<<endl;
        cout<<"Tail is at : "<<tail->data<<endl;
    }
}

void inserttail(node* &tail ,node* &head, int data)
{
    if(tail == NULL)
    {
        node* temp = new node(data);
        tail= temp;
        head=temp;
    }

    else
    {
        node* temp = new node(data);
        tail-> next = temp;
        tail= temp;

    }

}

void insertany(node* &head , node* &tail , int position , int data )
{
    if(position==1)
    {
        inserthead(head,tail,data);
    }

    else
    {
        node *temp = new node(data);

        node* prev=head;
        int count=1;

        while(count<position-1)
        {
            prev = prev->next;
            count++;

        }

        temp->next = prev -> next;
        prev->next =temp;

        if(temp->next==NULL)
        {
            tail=temp;
        }


    }
}

void deletenode(node* &head,int position, int data, node* &tail)
{
    if(position==1)
    {
        
        node* temp= head;
        
        head=head->next;
        //temp->next=NULL;
        
        delete temp;
        
    }
    else
    {
        node* prev=NULL;
        node* curr=head;

        while(curr->data != data)
        {
            prev=curr;
            curr=curr->next;
        
        }

        if(curr->next==NULL)
        {
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
    

}

int main()
{
    node* head=NULL;
    node* tail=NULL;

    print(head ,tail);
    cout<<endl;

    inserthead(head, tail ,40);
    print(head ,tail);
    cout<<endl;

    inserttail(tail,head, 50);
    print(head ,tail);
    cout<<endl;

    inserthead(head,tail,30);
    print(head ,tail);
    cout<<endl;

    inserttail(tail,head,60);
    print(head ,tail);
    cout<<endl;

    insertany(head,tail,1,20);
    insertany(head,tail,5,55);
    insertany(head,tail,7,70);

    print(head , tail);
    cout<<endl;

    deletenode(head,1,20,tail);
    print(head , tail);
    cout<<endl;

    return 0;

}