//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities
void dfs(int i,vector<pair<int,int>> adj[],int& ans,vector<int>& dis)
    {
        for(auto it:adj[i])
        {
            if(dis[it.first] > it.second)
            {
                dis[it.first] = it.second;
                ans = min(ans,it.second);
                dfs(it.first,adj,ans,dis);
            }
           
        }
    }
    int minScore(int n, vector<vector<int>>& roads) 
    {
         vector<pair<int,int>> adj[n];
         vector<int> dis(n,INT_MAX);
         for(int i=0;i<roads.size();i++)
         {
             adj[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
             adj[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});
         }
         int ans=INT_MAX;
         dfs(0,adj,ans,dis);
         return ans;
    }
