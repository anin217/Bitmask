#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll arr[100];
ll p[100];
ll dp[1<<15][15][15];

ll bcnt(ll num)
{
    return __builtin_popcountll(num);

}

ll solve(ll bm,ll i,ll j,ll n)
{
    ll po=pow(2,n)-1;
    if(bm==po)
        return 0;
    else if(dp[bm][i][j]!=-1) return dp[bm][i][j];
    else{
        ll ret=1000000000;
        ll pos=bcnt(bm);
        ll tmp=arr[i]^arr[j];
         for(ll k=0;k<n;k++)
         {
           if((bm>>k&1)==0)
             {
                ret=min(ret,solve(bm|(1<<k),k,i,n)+(tmp^arr[k])*p[pos]);
             }
         }
         dp[bm][i][j]=ret;
         return ret;
    }
}

int main()
{
    ll n,t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++) cin>>arr[i];
        for(i=0;i<n;i++) cin>>p[i];
        memset(dp,-1,sizeof(dp));
        ll ret=1000000000000;
        ll bm=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                ret=min(ret,solve((1<<i)|(1<<j),i,j,n));
            }
        }
        cout<<ret<<endl;
    }


}
