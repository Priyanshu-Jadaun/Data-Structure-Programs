
#include<iostream>
#include<stack>
using namespace std;

void delete_middle(stack<int> &s , int count,int size)
{
    if(count==(size/2))
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    delete_middle(s,count+1,size);
    s.push(num);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int n=s.size();
    delete_middle(s,0,n);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}