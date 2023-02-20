
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

Node* sort_zero_one_two(Node* &head)
{
    if(head == NULL)
    {
        return head;
    }
    else
    {
        Node* temp =head;
        int count_0=0;
        int count_1=0;
        int count_2=0;

        while(temp!= NULL)
        {
            if(temp->data ==0)
            {
                count_0 ++;
            }
            if(temp->data == 1)
            {
                count_1++;
            }
            if(temp->data == 2)
            {
                count_2++;
            }

            temp = temp->next;
        }

        Node* curr= head;
        while(count_0 !=0)
        {
            curr->data =0;
            count_0--;
            curr= curr->next;
        }

        while(count_1 != 0)
        {
            curr->data =1;
            count_1--;
            curr = curr->next;
        }

        while(count_2 != 0)
        {
            curr->data =2;
            count_2--;
            curr = curr->next;
        }

        return head;
    }
}

Node* sort(Node* &head)  //  ANOTHER WAY
{
    if(head == NULL)
    {
        return head;
    }
    else
    {
        Node* zero_head = new Node(-1);
        Node* one_head = new Node(-1);
        Node* two_head = new Node(-1);
        Node* zero_tail = zero_head;
        Node* one_tail = one_head;
        Node* two_tail = two_head;

        Node* curr = head;
        while(curr != NULL)
        {
            int value = curr->data;
            if(value==0)
            {
                insertAttail(0,zero_tail);
            }
            if(value==1)
            {
                insertAttail(1,one_tail);
            }
            if(value==2)
            {
                insertAttail(2,two_tail);
            }

            curr = curr->next;
        }
        if(one_head->next != NULL)
        {
            zero_tail->next = one_head->next;
            one_tail->next = two_head->next;
        }
        else
        {
            zero_tail->next = two_head->next;
        }

        Node* ans = zero_head->next;
        delete zero_head;
        delete one_head;
        delete two_head;

        return ans;
        
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
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    
    insertAttail(2,tail);
    insertAttail(0,tail);
    insertAttail(0,tail);
    insertAttail(0,tail);
    insertAttail(1,tail);
    insertAttail(2,tail);
    insertAttail(1,tail);

    insertAtany(3,2,head,tail);
    print(head);

    cout<<"Sort   "<<endl;

    Node* temp = sort(head); 
    print(temp);
    cout<<endl;


    return 0;

}