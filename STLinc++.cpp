#include<iostream>
#include<array>
#include<stack>
using namespace std;

int main()
{
    // STL ==> ARRAY

    // array<int,4> a ={1,2,3,4};
    // int size=a.size();

    // for(int i=0;i<size;i++)
    // {
    //     cout<<a[i]<<"   ";
    // }
    // cout<<endl;

    // cout<<"Element at index 2 "<<a.at(2)<<endl;
    // cout<<"Is empty or not "<<a.empty()<<endl;

    // cout<<"Element at 1st position "<<a.front()<<endl;
    // cout<<"Elemet at last position "<<a.back()<<endl;

    stack<int> a;
    a.push(2);
    a.push(3);
    a.push(5);
    a.push(7);

    cout<<a.size()<<endl;
    cout<<a.top()<<endl;
    cout<<a.empty()<<endl;

    cout<<"Elements are "<<endl;
    while(!a.empty())
    {
        cout<<a.top()<<endl;
        a.pop();
    }
    cout<<endl;
    return 0;
}
