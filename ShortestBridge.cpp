//https://leetcode.com/problems/shortest-bridge/description/
 bool check(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    x = i,y = j;
                    break;
                }
            }
        }
        queue<pair<int,int>> q,q1;
        q.push({x,y});
        grid[x][y] = -1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty())
        {
            auto it = q.front();
            q1.push(it);
            q.pop();
            for(int k=0;k<4;k++)
            {
                int p = it.first+dx[k];
                int r = it.second+dy[k];
                if(check(p,r,n,m) && grid[p][r]==1)
                {
                    q.push({p,r});
                    grid[p][r] = -1;
                }
            }
        }
        int cnt=0;
        bool f=false;
        // while(!q1.empty())
        // {
        //     auto it = q1.front();
        //     q1.pop();
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        while(!q1.empty())
        {
            int size = q1.size();
            while(size--)
            {
                auto it = q1.front();
                q1.pop();
                for(int i=0;i<4;i++)
                {
                    int p = it.first+dx[i];
                    int r = it.second+dy[i];
                    if(check(p,r,n,m))
                    {
                        if(grid[p][r]==1)
                        {
                            f=true;
                            break;
                            
                        }
                        else if(grid[p][r]==0){
                            q1.push({p,r});
                            grid[p][r] = -1;
                        }
                    }
                }
                if(f)
                break;
            }
            cnt++;
            if(f)
            break;
        }
        return cnt-1;
    }
