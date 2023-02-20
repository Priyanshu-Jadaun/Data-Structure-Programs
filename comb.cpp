
#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    return n*fact(n-1);
    
}
int main()

{
    int n,r;
    cin>>n>>r;

    // int comb = (fact(n) / (fact(n-r)*fact(r)));
    float comb = 1;
    int a = r;

    for(int i=1;i<=a;i++)
    {

        comb = comb*((((n-i+1)*1.00)/(r-i+1)));
    }
    cout<<comb<<endl;
    return 0; 
}