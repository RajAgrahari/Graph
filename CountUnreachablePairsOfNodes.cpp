//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
void dfs(int i,vector<int> adj[],vector<bool>& vis,int& cnt)
    {
        vis[i] = true;
        cnt++;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,vis,cnt);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<bool> vis(n,false);
        vector<int> adj[n];
        vector<int> v;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               int cnt=0;
               dfs(i,adj,vis,cnt);
               v.push_back(cnt);
            }
        }
        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans += ((long long)v[i]*(long long)(n-v[i]));
            n -= v[i];
        }
        return ans;
    }
