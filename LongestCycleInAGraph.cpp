//https://leetcode.com/problems/longest-cycle-in-a-graph
void dfs(int i,vector<int> adj[],bool& f,int& cnt,vector<int>& dis,vector<bool>& dfsvis)
    {
        dis[i] = cnt;
        dfsvis[i] = true;
        cnt++;
        for(auto it:adj[i])
        {
            if(dis[it]==-1)
            dfs(it,adj,f,cnt,dis,dfsvis);
            else if(dfsvis[it]){
                f=true;
                cnt = cnt-dis[it];
                return;
            }
        }
        dfsvis[i] = false;

    }
    int longestCycle(vector<int>& edges) 
    {
         int ans=-1;
         vector<int> adj[edges.size()];
         for(int i=0;i<edges.size();i++)
         if(edges[i]!=-1)
         adj[i].push_back(edges[i]);
         vector<int> dis(edges.size(),-1);
         vector<bool> dfsvis(edges.size(),false);
         for(int i=0;i<edges.size();i++)
         {
             bool f = false;
             if(dis[i]==-1)
             {
                 int cnt=0;
                 dfs(i,adj,f,cnt,dis,dfsvis);
                 if(f)
                 ans = max(ans,cnt);
             }
         }
         return ans;

    }
