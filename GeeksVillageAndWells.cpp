//https://practice.geeksforgeeks.org/problems/5a1277ffc1ec1d3a63d1a5d6b3920dd3d1294261/1
bool check(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c)
    {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                q.push({i,j});
            }
        }
        int cnt=2;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> p = q.front();
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    if(check(x,y,n,m) && (c[x][y]=='H' || c[x][y]=='.') && ans[x][y]==INT_MAX)
                    {
                        ans[x][y] = cnt;
                        q.push({x,y});
                    }
                }
            }
            cnt+=2;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]!='H')
                ans[i][j] = 0;
                else{
                    if(ans[i][j]==INT_MAX)
                    ans[i][j] = -1;
                }
            }
        }
        return ans;
        
    }
