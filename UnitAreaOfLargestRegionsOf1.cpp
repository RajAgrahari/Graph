//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
bool check(int i,int j,int n,int m)
    {
        if(i>=0 && j>=0 && i<n && j<m)
        return true;
        return false;
    }
    int bfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        int dx[8] = {0,0,-1,-1,-1,1,1,1};
        int dy[8] = {-1,1,-1,0,1,-1,0,1};
        q.push({i,j});
        grid[i][j]=0;
        int cnt=1;
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int k=0;k<8;k++)
            {
                if(check(x+dx[k],y+dy[k],n,m) && grid[x+dx[k]][y+dy[k]]==1)
                {
                    grid[x+dx[k]][y+dy[k]]=0;
                    cnt++;
                    q.push({x+dx[k],y+dy[k]});
                }
            }
            
        }
        return cnt;
    }
    int findMaxArea(vector<vector<int>>& grid) 
    {
          int n = grid.size();
          int m = grid[0].size();
          int ans=-1;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(grid[i][j]==1)
                  {
                      ans = max(ans,bfs(i,j,n,m,grid));
                  }
              }
          }
          if(ans==-1)
          return 0;
          return ans;
    }
