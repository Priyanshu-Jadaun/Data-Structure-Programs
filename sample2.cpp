#include<iostream>
using namespace std;
int main()
{
    int arr[5]={2,4,6,8,10};
    int sum=0;
    set<int> s;
    for(int i=0;i<5;i++)
    {
        sum = sum+arr[i];
        s.insert(sum);
    }
    for(auto i:s)
    {
    cout<<i<<endl;
    }
    return 0;
}
