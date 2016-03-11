#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll dp[(1<<18)][50];
ll arr[100];
ll hsh[22][22];
ll m;

ll bitcnt(ll num)
{
    return __builtin_popcountll(num);
}

ll solve(ll bm,ll in,ll n)
{

    if(dp[bm][in]!=-1) return dp[bm][in];

    else if(bitcnt(bm)>=m) return 0;

    else
    {
        ll ret =-1;
        for(ll j=0;j<n;j++)
        {
            if((bm&(1<<j))==0)
            ret=max(ret,solve(bm|(1<<j),j,n)+arr[j]+hsh[in][j]);
        }
        dp[bm][in]=ret;
        return ret;
    }
}


int main()
{

    ll n,k,a,b,c;
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++) cin>>arr[i];

        memset(dp,-1,sizeof(dp));

    for(ll i=0;i<k;i++)
    {
        cin>>a>>b>>c;
        hsh[a-1][b-1]=c;
    }
    ll ret=-1000;
    ll bm=0;
    for(ll i=0;i<n;i++)
    {
        ret=max(ret,solve(bm|(1<<i),i,n)+arr[i]);
    }
    cout<<ret<<endl;
}
