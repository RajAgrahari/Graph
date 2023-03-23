//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
void dfs(int i,vector<int> adj[],vector<int>& vis)
    {
        vis[i] = true;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
         vector<int> adj[n];
         int num = connections.size();
         for(int i=0;i<num;i++)
         {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
         }
         
         vector<int> vis(n,false);
         int cnt=0;
         for(int i=0;i<n;i++)
         {
             if(!vis[i])
             {
                 cnt++;
                dfs(i,adj,vis);
             }
         }
         int x = (cnt-1);
         if(num<(n-1))
         return -1;
         return x;

    }
