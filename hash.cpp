#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // int n;
    // cout<<"Enter number of elments "<<endl;
    // cin>>n;

    // int x;
    // int r ;
    // vector<int>  h[15];
    
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Enter number "<<endl;
    //     cin>>x;
    //     r = x % 10;
    //     h[r].push_back(x);

    // }
    
    vector<int> a;
    for(int i=0;i<5;i++)
    {
        a.push_back(i);
    }
    for(auto i:a)
    {
        cout<<a<<"  ";
    }
    cout<<endl;
    
    return 0;
}