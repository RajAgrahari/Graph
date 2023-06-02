//https://leetcode.com/problems/detonate-the-maximum-bombs/description/
int dfs(int i,vector<int> adj[],vector<int>& vis)
    {
        vis[i] = 1;
        int temp = 1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                temp += dfs(it,adj,vis);
            }
        }
        return temp;
    }
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        vector<int> adj[n];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long d1 = (long long)(bombs[i][0]-bombs[j][0])*(bombs[i][0]-bombs[j][0]);
                    long long d2 = (long long)(bombs[i][1]-bombs[j][1])*(bombs[i][1]-bombs[j][1]);
                    long long d = d1+d2;
                    if(d <= (long long)bombs[i][2]*bombs[i][2])
                    {
                        adj[i].push_back(j);
                    }
                }
                
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            int cnt = dfs(i,adj,vis);
            ans = max(ans,cnt);
        }
        return ans;
    }
