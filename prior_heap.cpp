
#include<iostream>
using namespace std;

void pq_insert(int arr[],int *size,int data)
{
    arr[*size]=data;
    int x = *size;

    int y = (*size-1)/2;

    while(x>0 && arr[x]<arr[y])
    {
        swap(arr[x],arr[y]);
        x= y;
        y= (x-1)/2;
    }

    *size = *size+1;

}

void min_heapify(int arr[],int i, int *size)
{
    while((2*i)+1 <= (*size-1))
    {
        int l =(2*i) + 1;
        int r =(2*i) + 2;
        int min = l;

        if(r<= *size-1)
        {
            if(arr[r]<arr[l])
            {
                min = r;
            }
            if(arr[min]<arr[i])
            {
                swap(arr[min],arr[i]);
            }
            else
            {
                break;
            }
        }
        i=min;
    }
}

int pq_delete(int arr[],int *size)
{
    int x =arr[0];
    arr[0] = arr[*size-1];
    *size = *size-1;

    min_heapify(arr,0,size);

    return x;
}

int main()
{
    int size = -1;
    int arr[40];

    pq_insert(arr,&size,20);
    pq_insert(arr,&size,14);
    pq_insert(arr,&size,12);
    pq_insert(arr,&size,31);
    pq_insert(arr,&size,7);
    pq_insert(arr,&size,11);
    pq_insert(arr,&size,13);
    pq_insert(arr,&size,7);

    int i = 0;
    cout<<endl;
    cout << "Priority Queue : ";
    while (i <= size) {
        cout << arr[i] << " ";
        i++;
    }
    cout<<endl;

    int x = pq_delete(arr,&size);
    cout<<x<<endl;

    i = 0;
    cout<<endl;
    cout << "Priority Queue : ";
    while (i <= size) {
        cout << arr[i] << " ";
        i++;
    }
    cout<<endl;

    return 0;
}