
#include<iostream>
using namespace std;

class cqueue
{
    public:
    char data;
    int rear,front;
    char *arr;
    int size;

    cqueue(int size)
    {
        this->size = size;
        rear = front = -1;
        arr = new char[size];

    }

    void Enqueue(char data)
    {
        if((rear==(size-1) && front==0)|| rear == front-1)
        {
            cout<<"Queue is full"<<endl;
        }
        else if(front==-1)
        {
            rear = front = 0;

        }
        else if(rear == size-1 && front!=0)
        {
            rear = 0;
        }
        else
        {
            rear ++;
        }

        arr[rear] = data;
    }

    char Dequeue()
    {
        if(front==-1)
        {
            cout<<"Quee is empty"<<endl;
            return '\0';
        }
        char x = arr[front];
        arr[front]=-1;
        if(front==rear)
        {
            front=rear = -1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return x;
    }
    bool Isempty()
    {
        if((rear==(size-1) && front==0)|| rear == front-1)
        {
            cout<<"Queue is full"<<endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    char qfront()
    {
        if(front==-1 && rear==-1)
        {
            return '\0';
        }
        else
        {
            return (arr[front]);
        }
    }
};


int main()
{
    cqueue q(5);
    q.Enqueue('a');
    q.Enqueue('b');
    q.Enqueue('c');
    q.Enqueue('d');
    q.Enqueue('e');
    q.Enqueue('f');

    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;

    q.Enqueue('g');
    cout<<q.qfront()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.qfront()<<endl;

    return 0;

}