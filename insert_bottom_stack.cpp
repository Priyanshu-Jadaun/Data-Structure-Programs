
#include<iostream>
#include<stack>
using namespace std;

void insert_bottom(stack<int> &s , int num)
{
    if(s.empty())
    {
        s.push(num);
    }
    else
    {
        int x =s.top();
        s.pop();
        insert_bottom(s,num);
        s.push(x);
    }
}

int main()
{
    stack<int> s;
    s.push(6);
    s.push(9);
    s.push(12);
    s.push(15);

    insert_bottom(s,3);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    return 0;
}