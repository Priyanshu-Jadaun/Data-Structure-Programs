
#include<iostream>
#include<stack>
using namespace std;

void insert_sort(stack<int> &s , int element )
{
    if(s.empty() || (s.top() < element))
    {
        s.push(element);
        return;
    }

    int n = s.top();
    s.pop();

    insert_sort(s,element);

    s.push(n);
}

void sort(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    sort(s);

    insert_sort(s,num);

}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(30);
    s.push(50);
    s.push(20);
    s.push(5);

    sort(s);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;

}