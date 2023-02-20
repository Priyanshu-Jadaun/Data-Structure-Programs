
#include<iostream>
using namespace std;

bool safe(int **arr,int **sol,int x,int y,int n)
{
    if(x>=0 && x<(n) && y>=0 && y<(n) && sol[x][y]==0 && arr[x][y]==1)
    {
        return true;
    }
    
    else
    {
        return false;
    }

}

void path(int **arr,int **sol,int x,int y,string ans,int n)
{
    //base case
    if(x==(n-1) && y==(n-1))
    {
        cout<<"Reached "<<endl;
        cout<<ans<<endl;
        return;
    }
    
    sol[x][y]=1;
    char ch;
    int newx = x;
    int newy = y-1;

    if(safe(arr,sol,newx,newy,n))
    {
        //left
        ch='L';
        cout<<"Left"<<endl;
        path(arr,sol,x,y-1,(ans+ch),n);
        
    }

    newx = x;
    newy = y+1;
    //right
    if(safe(arr,sol,newx,newy,n))
    {
        ch='R';
        cout<<"Rigtht"<<endl;
        path(arr,sol,x,y+1,(ans+ch),n);
        
    }
        
    newx = x-1;
    newy = y;
    //up
    if(safe(arr,sol,newx,newy,n))
    {
        ch='U';
        cout<<"UP"<<endl;
        path(arr,sol,x-1,y,(ans+ch),n);
    }
        
    newx = x+1;
    newy = y;
    //down
    if(safe(arr,sol,newx,newy,n))
    {
        ch='D';
        cout<<"down"<<endl;
        path(arr,sol,x+1,y,(ans+ch),n);
    }
    
    sol[x][y]=0;
    
}

int main()
{
    int n;
    cout<<"Enter size of maze"<<endl;
    cin>>n;

    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }

    cout<<"Enter maze for rat "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int **sol = new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i] = new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }

    path(arr,sol,0,0,"",n); // fumction to find total paths
    cout<<endl;
    return 0;
}