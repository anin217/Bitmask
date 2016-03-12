#include <bits/stdc++.h>

using namespace std;
#define ll int


ll primebits[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

ll dp[(1<<15)+5][100];
ll arr[100];
int check(int mask,int num)
   {
      // cout<<"back from check"<<endl;
   	    int reply=0,f=0;
   	  for(int i=0;i<15;i++)
   	   {
   	   	  int kk=primebits[i];
   	   	 if((mask & (1<<i)) && num%kk==0)
   	   	  {
   	   	  	 f=1;
   	   	  	 break;
		  }
		  else if(num%kk==0)
		   {
		   	reply=   reply | (1<<i);
		   }
		  }
		  if(f==1) return -1;
		  else return reply;
		  //cout<<"back from check"<<endl;
   }

ll solve(ll bm,ll i,ll n)
{
 //  cout<<bm<<" "<<i<<endl;
   ll p=pow(2,15)-1;

    if(bm==p  || i>=n) return 0;

    else if(dp[bm][i]!=-1) return dp[bm][i];
     else
     {
           ll ret=0;
           ret=max(ret,solve(bm,i+1,n));
           int nm=check(bm,arr[i]);
           if(nm!=-1)
           ret=max(ret,solve(nm | bm,i+1,n)+1);
           dp[bm][i]=ret;
         return ret;

     }
}
int main()
{

    ll t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int fk=0;
        ll kk=0;

        ll x;
        for(i=0;i<n;i++)
            {
                cin>>x;
                {
                    if(x==1)
                    fk++;
                    else
                     arr[kk++]=x;
                }
            }
       n=kk;
        ll ret=0;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
             ll bm=0;
            for(j=0;j<15;j++)
            {
                if(arr[i]%primebits[j]==0)
                {
                   // cout<<j<<" hreeee"<<endl;
                    //int x=primebits[j];
                    bm=bm|(1<<j);
                }
            }
            // cout<<"calling with bm "<<bm<<endl;
                 ret=max(ret,solve(bm,i,n)+1);
                // cout<<ret<<endl;
               //  cout<<ret<<endl;
        }
   // cout<<ret<<endl;
            cout<<ret+fk<<endl;
    }
}
