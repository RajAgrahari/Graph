//https://codeforces.com/contest/1833/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);
bool dfs(ll i,ll p,vector<ll> adj[],vector<bool>& vis)
{
    vis[i] = true;
    for(ll ch:adj[i])
    {
        if(ch!=p)
        {
            if(vis[ch])
            {
                return true;
            }
            else
            {
                if(dfs(ch,i,adj,vis))
                return true;
            }
        }
    }
    return false;
}
int main()
{
    NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        vector<ll> adj[n+1];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(adj[i+1].size()==1 && adj[i+1][0]!=a[i])
            adj[i+1].push_back(a[i]);
            else if(adj[i+1].size()==0)
            adj[i+1].push_back(a[i]);
            
            if(adj[a[i]].size()==1 && adj[a[i]][0]!=(i+1))
            adj[a[i]].push_back(i+1);
            else if(adj[a[i]].size()==0)
            adj[a[i]].push_back(i+1);
        }
        
        vector<bool> vis(n+1,false);
      
        ll mx=0,mi=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                mx++;
                bool f = dfs(i,-1,adj,vis);
                if(f)
                mi++;
            }
        }
        cout<<min(mi+1,mx)<<' '<<mx<<'\n';

    }
    return 0;
}
