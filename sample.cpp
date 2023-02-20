
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

Node* insert(Node* head)
{
    Node* temp = new Node(10);
    if(head == NULL)
    {
        head = temp;

    }
    return head;
}

void traverse(Node* head)
{
    Node* curr = new Node(20);
    Node* temp = head;
    temp->next = curr;

    cout<<"Data ::  "<<temp->data<<endl;
    cout<<"Address ::  "<<temp<<endl;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = head ;
    // Node* up = new Node(10);
    // temp = up;
    cout<<"Data ::  "<<head->data<<endl;
    cout<<"Address ::  "<<head<<endl;

    traverse(head);
    cout<<head->next->data<<endl;
    return 0;
}