//https://codeforces.com/contest/580/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);
void dfs(ll& ans,ll i,vector<ll> adj[],vector<ll>& cat,ll prev,ll m,ll par)
{
    if(par!=-1 && adj[i].size()==1)
    {
        ans++;
        return;
    }
    for(ll x:adj[i])
    {
        if(x!=par)
        {
             if(cat[x]==1)
            {
                if(prev!=m)
                dfs(ans,x,adj,cat,prev+1,m,i);
            }
            else
            dfs(ans,x,adj,cat,0,m,i);
        }
    }
}
int main()
{
NOOB CODER SOLUTION
        ll n,m;
        cin>>n>>m;
        vector<ll> cat(n);
        for(ll i=0;i<n;i++)
        cin>>cat[i];
        vector<ll> adj[n];
        for(ll i=0;i<n-1;i++)
        {
            ll x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
            ll ans=0;
            if(cat[0]==1)
            dfs(ans,0,adj,cat,1,m,-1);
            else
            dfs(ans,0,adj,cat,0,m,-1);
            cout<<ans<<endl;
        
    return 0;
}
