
#include<iostream>
using namespace std;

class Queue
{

    public:
    int data;
    int* arr;
    int size;
    int front,rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = 0;
    }

    void Enqueue(int data)
    {
        if(rear==size)
        {
            cout<<"Its Full"<<endl;
            return;
        }
        else
        {
            arr[rear]=data;
            rear++;
            return;
        }
    }

    int Dequeue()
    {
        if(front==rear)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
    
        else
        {
            int ans = arr[front];
            arr[front] =-1;
            front++;
            if(front==rear)
            {
                front = rear =0;
            }
            return ans;
        }
    }

    int front_ele()
    {
        if(front==rear)
        {
            return -1;
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
            cout<<"Empty"<<endl;
            return true;
        }
        else
        {
            cout<<"Filled"<<endl;
            return false;
        }
    }
};

int main()
{
    Queue q(5);
    cout<<q.front_ele()<<endl;

    cout<<q.Isempty()<<endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    cout<<q.Isempty()<<endl;
    cout<<q.front_ele()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Isempty()<<endl;
    cout<<q.front_ele()<<endl;
    q.Enqueue(70);
    cout<<q.Dequeue()<<endl;
    cout<<q.Isempty()<<endl;
    
    return 0;
    
}