
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string str;
    cout<<"Enter a string "<<endl;
    cin>>str;

    stack <char> s;

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch =='-' || ch=='*' || ch=='/')
        {
            s.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                int flag=0;
                while(s.top()!='(')
                {
                    if(s.top()=='+' || s.top() =='-' || s.top()=='*' ||s.top()=='/')
                    {
                        flag=1;
                        s.pop();
                    }
                    else
                    {
                        cout<<"Yes"<<endl;
                        return true;
                    }
                }
                s.pop();
                if(flag==0)
                {
                    cout<<"Yes"<<endl;
                    return true;
                }
                

            }
        }
    }
    cout<<"no"<<endl;
    return false;
}
