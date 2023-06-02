//https://practice.geeksforgeeks.org/problems/santa-banta2814/1
vector<int> v;
    void precompute()
    {
        vector<bool> prime(1000001,true);
        prime[0] = prime[1] = false;
        for(int i=2;i<=1000000;i++)
        {
            if(prime[i])
            {
                v.push_back(i);
                for(int j=2*i;j<=1000000;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
    }
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,int& cnt)
    {
        vis[i] = 1;
        cnt++;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,vis,cnt);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        vector<int> vis(n+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int cnt =0;
                dfs(i,g,vis,cnt);
                ans = max(ans,cnt);
            }
        }
        if(ans==1)
        return -1;
        return v[ans-1];
        
    }
