#include<iostream>
using namespace std;

class Queue
{
    public:
    int data;
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = front =0;
    }
    
    void Enqueue(int data)
    {
        if(rear == size)
        {
            cout<<"Its full"<<endl;

        }
        else
        {
            arr[rear] = data;
            rear++;  
        }
    }

    int Dequeue()
    {
        if(rear == front)
        {
            cout<<"Its Empty "<<endl;
            return -1;
        }
        else
        {
            int x = arr[front];
            arr[front] = -1;
            front++;

            if(front==rear)
            {
                front = rear =0;
            }
            return x;
        }
    }

    int q_front()
    {
        if(front == rear)
        {
            cout<<"Its Empty "<<endl;
        }
        else
        {
            return arr[front];
        }
    }

    bool Isempty()
    {
        if(front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Enqueue(70);
    q.Enqueue(80);
    cout<<"Front element is "<<q.q_front()<<endl;
    cout<<"Eements are :: "<<endl;
    while(!q.Isempty())
    {
        cout<<q.q_front()<<endl;
        q.Dequeue();
    }

    return 0;
}