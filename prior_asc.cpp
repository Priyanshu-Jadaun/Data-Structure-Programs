#include<iostream>
using namespace std;

void array_insert(int arr[],int size,int ind,int data)
{
    
    for(int j=size-1;j>=ind;j--)
    {
        arr[j+1] = arr[j];
    }
    arr[ind]=data;
    size = size+1;
    
}

void pqinsert(int arr[],int size,int data)
{
    int i=0;
    while( i<size && data>=arr[i])
    {
        i=i+1;
    }
    array_insert(arr,size,i,data);
    
}

void pq_deletion(int arr[],int size,int index)
{
    int j=index;
    while(j<size-1)
    {
        arr[j] = arr[j+1];
        j++;
    }
    arr[size-1]=0;
}

int main()
{
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    int size = n+1;
    int arr[size],data;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Element to insert"<<endl;
    cin>>data;

    pqinsert(arr,size,data);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"    ";
    }
    cout<<endl<<endl;

    int del =0;
    cout<<"Enter index to delete(0-base indexing) : "<<endl;
    cin>>del;

    pq_deletion(arr,size,del);


    for(int i=0;i<size-1;i++)
    {
        cout<<arr[i]<<"    ";
    }

    return 0;

}