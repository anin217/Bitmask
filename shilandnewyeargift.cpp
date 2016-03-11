#include <bits/stdc++.h>

using namespace std;

#define ll long long int


ll arr[1005];
ll dp[(1<<15)+10][40];

ll solve(ll bm, ll i,ll n)
{
    ll p=pow(2,n)-1;
    if(bm==p) return 0;

     else if(dp[bm][i]!=-1) return dp[bm][i];

     else
     {
         ll ret=0;

         for(ll j=0;j<n;j++)
         {
             if((bm>>j&1)==0)
             ret=max(ret,solve(bm|(1<<j),j,n)+__gcd(arr[i],arr[j]));
         }
         dp[bm][i]=ret;
         return ret;
     }
}

int main()
{

    int n;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>arr[i];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    ll ret=0;
    ll bm=0;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        ret=max(ret,solve((bm|1<<i),i,n));
    }
    cout<<ret<<endl;



}
