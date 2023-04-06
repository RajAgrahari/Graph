//https://leetcode.com/problems/number-of-closed-islands/
 bool check(int i,int j,int n,int m)
    {
        if(i>=0 && j>=0 && j<m && i<n)
        return true;
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        grid[i][j] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            if(check(i+dx[k],j+dy[k],n,m) && grid[i+dx[k]][j+dy[k]]==0)
            dfs(i+dx[k],j+dy[k],n,m,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==0)
            dfs(i,m-1,n,m,grid);
            if(grid[i][0]==0)
            dfs(i,0,n,m,grid);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==0)
            dfs(n-1,i,n,m,grid);
            if(grid[0][i]==0)
            dfs(0,i,n,m,grid);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(i,j,n,m,grid);
                    c++;
                }
            }
        }
        return c;

    }
