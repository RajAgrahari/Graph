//https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1
bool check(int x,int y,int n,int m)
    {
        if(x>=0 && x<n && y>=0 && y<m)
        return true;
        return false;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==1)
            {
                q.push({i,0});
              matrix[i][0] = 0;
            }
            if(matrix[i][m-1]==1)
            {
                q.push({i,m-1});
                matrix[i][m-1] = 0;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]==1)
            {
                q.push({0,j});
               matrix[0][j] = 0;
            }
            if(matrix[n-1][j]==1)
            {
                q.push({n-1,j});
                matrix[n-1][j] = 0;
            }
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = it.first + dx[i];
                int y = it.second + dy[i];
                if(check(x,y,n,m) && matrix[x][y]==1)
                {
                    matrix[x][y]=0;
                    q.push({x,y});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
               {
                  q.push({i,j});
                   matrix[i][j] = 0;
                  while(!q.empty())
                    {
                        auto it = q.front();
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int x = it.first + dx[i];
                            int y = it.second + dy[i];
                            if(check(x,y,n,m) && matrix[x][y]==1)
                            {
                                matrix[x][y]=0;
                                q.push({x,y});
                            }
                        }
                    }
                    cnt++;
               }
            }
            
        }
        return cnt;
        
        
    }
