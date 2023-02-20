#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter number of vertices "<<endl;
    cin>>v;

    cout<<"Enter numbe of edges "<<endl;
    cin>>e;

    vector<int> Adj_list[v];
    int ans[7][7]={0};
    int inc_mat[10][10]={0};

    for(int i=1;i<=e;i++)
    {
        int a,b;
        cout<<"Enter data for edge "<<i<<endl;
        cin>>a>>b;

        Adj_list[a].push_back(b);
        Adj_list[b].push_back(a);
        ans[a][b]=1;
        ans[b][a]=1;
        inc_mat[i][a]=1;
        inc_mat[i][b]=1;
    }

    cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<Adj_list[i].size();j++)
        {
            cout<<Adj_list[i][j]<<"  ";
        }
        cout<<endl;
    }

    // int ans[v][v]={0};

    // for(int i=0;i<v;i++)
    // {
        
    //     for(int j=0;j<v;j++)
    //     {
    //         if(Adj_list[i][j]!=0)
    //         {
    //             ans[i][j]=1;
    //         }
    //     }
        
    // }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Order "<<endl;
     for(int i=0;i<v;i++)
    {
        
        cout<<"Order "<<Adj_list[i].size()<<"  ";
        
        cout<<endl;
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<e;j++)
        {
            cout<<inc_mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}