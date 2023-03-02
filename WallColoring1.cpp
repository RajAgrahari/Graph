// https://practice.geeksforgeeks.org/problems/9dacc32ad062be6e2ba8f6c41aad0b2b2376397d/1
int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int k = costs[0].size();
        if(k==1 && n!=1)
        return -1;
        vector<vector<int>> dp(n,vector<int>(k,-1));
        for(int i=0;i<k;i++)
        dp[0][i] = costs[0][i];
        
        for(int i=1;i<n;i++)
        {
            int mincost = INT_MAX;
            int minidx = -1;
            for(int j=0;j<k;j++)
            {
                if(dp[i-1][j] < mincost)
                {
                    mincost = dp[i-1][j];
                    minidx = j;
                }
            }
            int mincost2 = INT_MAX;
            for(int j=0;j<k;j++)
            {
                if(j!=minidx && dp[i-1][j] < mincost2)
                {
                    mincost2 = dp[i-1][j];
                }
            }
            for(int j=0;j<k;j++)
            {
                if(j==minidx)
                dp[i][j] = mincost2 + costs[i][j];
                else
                dp[i][j] = mincost + costs[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<k;i++)
        ans = min(ans,dp[n-1][i]);
        return ans;
    
    }
