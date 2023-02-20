
#include<iostream>
using namespace std;

class twoStack
{
    public:

    int size;
    int *arr;
    int top1;
    int top2;

    twoStack(int size)
    {
        this->size = size;
        top1=-1;
        top2=size;
        arr = new int[size]; 
    }

    void push1(int num)
    {
        if(top2-top1 > 1)
        {
            top1++;
            arr[top1]=num;
        }
        else
        {
            cout<<" Stack Overflow"<<endl;
        }
    }

    void push2(int num)
    {
        if(top2-top1 > 1)
        {
            top2--;
            arr[top2]=num;
        }
        else
        {
            cout<<" Stack Overflow"<<endl;
        }
    }

    int pop1()
    {
        if(top1>=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout<<"stack underflows "<<endl;
            return -1;
        }
    }

    int pop2()
    {
        if(top2<=(size-1))
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout<<"stack underflows "<<endl;
            return -1;
        }
    }
};

int main()
{
    twoStack ts(8);
    ts.push1(2);
    ts.push1(4);
    ts.push1(6);
    ts.push1(8);
    ts.push1(10);
    ts.push2(12);
    ts.push2(14);
    ts.push2(16);
    ts.push2(18);
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<endl;
    return 0;
}