//https://leetcode.com/problems/01-matrix/description/
bool check(int i,int j,int n,int m,vector<vector<int>>& mat)
    {
        if(i<n-1 && mat[i+1][j]==0)
        return true;
        else if(j<m-1 && mat[i][j+1]==0)
        return true;
        else if(i>0 && mat[i-1][j]==0)
        return true;
        else if(j>0 && mat[i][j-1]==0)
        return true;

        return false;
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        queue<pair<int,int>> q; 
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                ans[i][j] = 0;
                if(mat[i][j]==1 && check(i,j,n,m,mat))
                {
                    ans[i][j] = 1;
                    q.push({i,j});
                }
                
            }
        }

        while(!q.empty())
        {
             auto [x,y] = q.front();
             q.pop();
             if(x>0 && ans[x-1][y]==INT_MAX)
             {
                ans[x-1][y] = min(ans[x][y]+1,ans[x-1][y]);
                q.push({x-1,y});
             }
             if(y>0 && ans[x][y-1]==INT_MAX)
             {
               ans[x][y-1] = min(ans[x][y]+1,ans[x][y-1]);
               q.push({x,y-1});
             }
             if(x<n-1 && ans[x+1][y]==INT_MAX)
             {
               ans[x+1][y] = min(ans[x][y]+1,ans[x+1][y]);
               q.push({x+1,y});
             }
             if(y<m-1 && ans[x][y+1]==INT_MAX)
             {
               ans[x][y+1] = min(ans[x][y]+1,ans[x][y+1]);
               q.push({x,y+1});
             }
        }
        return ans;
    }
