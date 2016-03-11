#include <bits/stdc++.h>

using namespace std;

vector <pair<pair <int,int> , int > > grph;
int dist[20][20];
int cost[60][60];
int  p2;
int solve(int bm,int i,int n)
{

        cout<<"hhhh "<<bm<<" "<<i<<endl;
    if(bm==p2)return 0;

    else if(cost[bm][i]!=-1) return cost[bm][i];

    else
    {
        int ret=1000;
        for(int j=0;j<n;j++)
        {
            if((bm>>j&1)==0 && dist[i][j]!=1000)
            {

                ret=min(ret,dist[i][j]+solve(bm|(1<<j),j,n));
            }
        }
        cost[bm][i]=ret;
        return ret;
    }

}
int main()
{
    int n,m;
    int i,j,a,b,c;
    cin>>n;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        dist[a][b]=c;
     //   dist[b][a]=c;
    }
    for(i=0;i<30;i++)
    {
        for(j=0;j<30;j++)
        {
            cost[i][j]=-1;
        }
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {if(dist[i][j]==0)
        {
            dist[i][j]=1000;
        }
        }
    }
    for(int i=0;i<n;i++)
    {

          for(int j=0;j<n;j++)
            cout<<dist[i][j]<<" ";
          cout<<endl;
    }
    int ret=INT_MAX;
    int bm=1;
p2=pow(2,n)-1;
cout<<"p2 "<<p2<<endl;
       ret=min(ret,solve(bm,0,n));
    cout<<ret<<endl;

}

