// https://leetcode.com/problems/rotting-oranges/
int orangesRotting(vector<vector<int>>& grid) {
          int count=0;
          int n = grid.size();
          int m = grid[0].size();
          queue<pair<int,int>> q;
          for(int i=0;i<grid.size();i++)
          {
              for(int j=0;j<grid[0].size();j++)
              {
                  if(grid[i][j]==2)
                    q.push({i,j});
              }
          }
          while(!q.empty())
          {
              int size = q.size();
              for(int i=0;i<size;i++)
              {
                  int x = q.front().first;
                  int y = q.front().second;
                  q.pop();
                  if(x>0 && grid[x-1][y]==1)
                  {
                      q.push({x-1,y});
                      grid[x-1][y]=2;
                  }
                  if(x<n-1 && grid[x+1][y]==1)
                  {
                      q.push({x+1,y});
                      grid[x+1][y]=2;
                  }
                  if(y>0 && grid[x][y-1]==1)
                  {
                      q.push({x,y-1});
                      grid[x][y-1]=2;
                  }
                  if(y<m-1 && grid[x][y+1]==1)
                  {
                      q.push({x,y+1});
                      grid[x][y+1]=2;
                  }
              }
                  if(q.size())
                  count++;
          }
           for(int i =0;i<n;i++)
                  for(int j =0;j<m;j++)
               if(grid[i][j]==1) return -1;
       
          return count;
        
    }
