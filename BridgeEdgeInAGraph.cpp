//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
void dfs(int i,vector<int> adj[],vector<bool>& vis)
    {
        vis[i] = true;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,vis);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
         vector<bool> vis(V,false);
         int cnt=0;
         for(int i=0;i<V;i++)
         {
             if(!vis[i])
             {
                cnt++;
                dfs(i,adj,vis);
             }
            
         }
         vis.assign(V,false);
        int idx1=0;
         for(int i=0;i<adj[c].size();i++)
         {
             if(adj[c][i]==d)
             {
                 idx1=i;
                 break;
             }
         }
         adj[c].erase(adj[c].begin()+idx1);
         int idx2=0;
         for(int i=0;i<adj[d].size();i++)
         {
             if(adj[d][i]==c)
             {
                 idx2=i;
                 break;
             }
         }
         adj[d].erase(adj[d].begin()+idx2);
         int cnt1=0;
         for(int i=0;i<V;i++)
         {
             if(!vis[i])
             {
                cnt1++;
                dfs(i,adj,vis);
             }
            
         }
         if(cnt!=cnt1)
         return true;
         return false;
    }
