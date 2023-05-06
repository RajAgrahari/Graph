//https://codeforces.com/contest/1829/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{
        if(edges.size()==0)
        return {0}; 
        
        vector<int> indegree(n+1, 0); 
        vector<bool> vis(n+1, 0); 
        queue<int> q;

        for(int i=1; i<n+1; i++){
            if(edges[i].size() == 1){
                q.push(i);
                vis[i] = true;
            }
            indegree[i] = edges[i].size();
        }
        
        while(n > 2){
            int sz = q.size();
            n-=sz; 
            while(sz--){
                auto node = q.front();q.pop();
                for(auto ch : edges[node]){ 
                    if(vis[ch])continue;
                    indegree[ch]--;
                    if(indegree[ch] == 1)
                    { 
                        vis[ch] = true;
                        q.push(ch);
                    }
                }
            }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
int main()
{
    NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(n+1);
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        vector<int> ans;
        ans = findMinHeightTrees(n,edges);
        for(int x:ans)
        {
            ll p = 0;
            bool f=true;
            for(auto it:edges[x])
            {
                    if(p==0)
                    p = edges[it].size();
                    else{
                        if(p!=edges[it].size())
                        {
                            f=false;
                            break;
                        }
                    }
            }
            if(f)
            {
                cout<<edges[x].size()<<' '<<p-1<<'\n';
            }
        }
        
    }
    return 0;
}
