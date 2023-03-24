//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
void dfs(int i,vector<int> adj[],int& cnt,vector<bool>& vis)
    {
        vis[i] = true;
        for(auto it:adj[i])
        {
            if(!vis[abs(it)])
            {
                if(it>0)
                {
                   cnt++;
                   dfs(it,adj,cnt,vis);
                }
                else
                dfs(abs(it),adj,cnt,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        int cnt=0;
        vector<bool> vis(n,false);
        dfs(0,adj,cnt,vis);
        return cnt;
    }
