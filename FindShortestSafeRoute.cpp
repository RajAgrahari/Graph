//https://practice.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
bool check(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size(),m = mat[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(mat[i][j]==0)
                 {
                     for(int k=0;k<4;k++)
                     {
                         if(check(i+dx[k],j+dy[k],n,m) && mat[i+dx[k]][j+dy[k]]==1)
                         mat[i+dx[k]][j+dy[k]]=-1;
                     }
                 }
             }
         }
         queue<pair<int,pair<int,int>>>q;
         vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            if(mat[i][0] == 1) {
                q.push({0,{i,0}});
                vis[i][0] = 1;
            }
        }
        
        int ans = INT_MAX;
        while(!q.empty()) {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
                
            if(c == m - 1)
                ans = min(ans,dist+1);    
            
            for(int k=0;k<4;k++) {
                int nx = r + dx[k];
                int ny = c + dy[k];
                
                if(check(nx,ny,n,m) and mat[nx][ny] == 1 and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
         
    }
