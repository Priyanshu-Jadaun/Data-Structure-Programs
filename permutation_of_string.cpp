#include<iostream>
using namespace std;

void permutation(string input,int index)
{
    if(index >= input.length())
    {
        cout<<input<<endl;
    }

    for(int i=index;i<input.length();i++)
    {
        swap(input[index],input[i]);
        permutation(input,index+1);
    }
}

int main()
{
    string str;
    cout<<"Enter a string "<<endl;
    cin>>str;

    permutation(str,0);
    cout<<endl;
    return 0;
}