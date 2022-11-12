
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define STACKSIZE 10

struct Stack
{
    int item[10];
    int TOP;
};



void initialise(Stack *s)
{
    s->TOP = -1;
}

bool IsEmpty(Stack *s)
{
    if (s->TOP == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void push(Stack* s,int x)
{
    if(s->TOP == (STACKSIZE-1))
    {
        cout<<"Stack overflow "<<endl;
        exit(1);
    }
    s->TOP = s->TOP + 1;
    s->item[s->TOP] = x;

}

int pop(Stack* s)
{
    if(IsEmpty(s))
    {
        cout<<"Stack underflows "<<endl;
        exit(1);
    }
    int x = s->item[s->TOP];
    s->TOP = s->TOP-1;
    return x;
}

int top(Stack* s)
{
    int x = s->item[s->TOP];
    return x; 
}

int main()
{
    // struct Stack s;

    Stack *s = new Stack;
    initialise(s);
    cout<<IsEmpty(s)<<endl;
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);
    cout<<top(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<top(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<top(s)<<endl;
    cout<<pop(s)<<endl;

    return 0;
}