
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
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"     ";
        temp = temp->next;
    }
}
Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* frwrd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwrd;
    }
    return prev;
}
void insertAttail(Node* &head ,Node* &tail , int val)
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        head = temp;
        tail= temp;
    }
    else
    {
        tail->next =temp;
        tail = temp;
    }
}
Node* add(Node* first , Node* second)
{
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry=0;
    while(first != NULL || second != NULL || carry != 0)
    {
        int val1=0;
        if(first!=NULL)
        {
            val1 = first->data;
        }
        int val2=0;
        if(second!= NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 +val2;
        int digit = sum%10;
        carry = sum/10;
    
        insertAttail(ansHead,ansTail,digit );

        if(first != NULL)
        {
            first = first->next;

        }
        if(second != NULL)
        {
            second = second->next;
        }
    }
    Node* f_ans = reverse(ansHead);
    return f_ans;

}

int main()
{
    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAttail(3,tail1);
    insertAttail(5,tail1);
    cout<<"Number 1:"<<endl;print(head1);
    Node* node2 = new Node(2);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAttail(4,tail2);
    insertAttail(6,tail2);
    cout<<"\nNumber 2:"<<endl;print(head2);
    Node* temp1 = reverse(head1);
    Node* temp2 = reverse(head2);
    Node* ans = add(temp1,temp2);
    cout<<"\nSum is"<<endl;
    print(ans);
    return 0;
}