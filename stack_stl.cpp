
#include<iostream>
#include<stack>

using namespace std;

class Stack
{
    public:
    int top ;
    int size;
    int *arr;

    Stack(int size)
    {
        arr = new int(size);
        top = -1;
        this->size = size;
    }

    void push(int n)
    {
        if((size-top)>1)
        {
            top = top+1;
            arr[top]=n;
        }
        else
        {
            cout<<"Stack overflows "<<endl;
        }
        
    }

    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is empty "<<endl;
            return -1;
        }
    }
     
    void pop()
    {
        if(top>=0)
        {
            top = top-1;
        }
        else
        {
            cout<<"Stack underflows "<<endl;
        }
    }

    bool isempty()
    {
        if(top>=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{

    Stack s(5);

    // stack<int> s;
    // cout<<"size of stack ::  "<<s.size()<<endl;

    // s.push(10);
    // s.push(20);
    // s.pop();
    // s.push(30);
    // cout<<s.top();
    // s.pop();
    // s.push(15);

    // cout<<s.empty()<<endl;
    // cout<<s.size()<<endl;

    // while(!(s.empty()))
    // {
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }

    s.push(10);
    s.push(20);
    s.pop();
    s.push(30);
    cout<<"Top Element is "<<s.peek()<<endl;
    s.pop();
    s.push(15);

    if(s.isempty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Stack elements are: "<<endl;
    while(!(s.isempty()))
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
    
    return 0;

}