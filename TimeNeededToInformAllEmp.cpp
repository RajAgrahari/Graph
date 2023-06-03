//https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({0,headID});
        int ans = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans = max(ans,it.first);
            for(auto ch:adj[it.second])
            {
                q.push({it.first+informTime[it.second],ch});
            }
        }
        return ans;
    }
