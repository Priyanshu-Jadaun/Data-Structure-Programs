#include<iostream>
using namespace std;

void print(int *ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<*(ptr+i)<<"   ";
    }
    cout<<endl;
}


void input(int* array,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>*(array+i);
    }
}

void output(int *array,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<(array+i)<<"  ";
    }
}
int main()
{
    // int n;
    // cin>>n;
    // int *ptr = &n;
    // cout<<&n<<endl;
    // cout<<ptr<<"   "<<*ptr<<endl;

    // int arr[n]={1,2,3,4};
    // int *ptr = arr;

    // cout<<arr<<endl;
    // cout<<ptr<<"   "<<*ptr<<endl;

    // for(int i=0;i<4;i++)
    // {
    //     cout<<(int)(arr+i)<<"   ";
    //     cout<<*(arr+i)<<"   ";
    // }
    // cout<<endl;
    
    int n;
    cin>>n;
    int a =sizeof(int);
    int *array = new int[n*a];
    cout<<"Enter "<<endl;
    input(array,n);
    cout<<"Elements are "<<endl;
    output(array,n);
    cout<<endl;
    // cout<<sizeof(int)<<endl;
    // cout<<sizeof(long long)<<endl;
    // char *ab = new char[4*sizeof(char)];
    // cout<<"Enter "<<endl;
    // for(int i=0;i<4;i++)
    // {
    //     cin>>*(ab+i);
    // }
    // cout<<"Elements are "<<endl;
    // for(int i=0;i<4;i++)
    // {
    //     cout<<*(ab+i)<<"  ";
    // }
    // cout<<endl;


    // delete []ab;

    return 0;
}