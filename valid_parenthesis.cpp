#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str;
    cin>>str;

    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];

        if(ch == '(' || ch =='[' ||ch =='{')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char top = s.top();
                if((ch == ')' && top =='(') || (ch == '}' && top =='{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    cout<<"Invalid "<<endl;
                    return false;
                }
            }
            else
            {
                cout<<"Invalid "<<endl;
                return false;
            }
        }
    }
    if(s.empty())
    {
        cout<<"Valid"<<endl;
    }
    else
    {
        cout<<"Invalid "<<endl;
    }

    return 0;
}