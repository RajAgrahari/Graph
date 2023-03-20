//https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1
bool check(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    int shortestXYDist(vector<vector<char>> grid, int n, int m) 
    {
         queue<pair<int,int>> q;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(grid[i][j]=='X')
                 q.push({i,j});
             }
         }
         vector<vector<bool>> vis(n,vector<bool>(m,false));
         int dx[] = {0,0,-1,1};
         int dy[] = {-1,1,0,0};
         int cnt=1;
         bool f=false;
         while(!q.empty())
         {
             int size = q.size();
             
             while(size--)
             {
                 auto it = q.front();
                 int x = it.first;
                 int y = it.second;
                 vis[x][y] = true;
                 q.pop();
                 for(int i=0;i<4;i++)
                 {
                     if(check(x+dx[i],y+dy[i],n,m) && !vis[x+dx[i]][y+dy[i]])
                     {
                         if(grid[x+dx[i]][y+dy[i]]=='O')
                         {
                             vis[x+dx[i]][y+dy[i]]=true;
                             q.push({x+dx[i],y+dy[i]});
                         }
                         else if(grid[x+dx[i]][y+dy[i]]=='Y')
                         {
                             f=true;
                             break;
                         }
                     }
                     
                 }
                 if(f)
                 break;
             }
             if(f)
             break;
             cnt++;
         }
         return cnt;
         
    }
