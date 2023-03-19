//https://leetcode.com/problems/check-knight-tour-configuration/
bool check(int x,int y,int n)
    {
        if(x>=0 && y>=0 && x<n && y<n)
        return true;
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
         int n = grid.size();
         queue<pair<int,int>> q;
         q.push({0,0});
         int cnt=0;
        bool f=false;
         while(!q.empty())
         {
             auto [i,j] = q.front();
             q.pop();
             cnt++;
             int dx[] = {i-1,i-1,i-2,i-2,i+1,i+1,i+2,i+2};
             int dy[] = {j-2,j+2,j+1,j-1,j+2,j-2,j-1,j+1};
             for(int k=0;k<8;k++)
             {
                 if(check(dx[k],dy[k],n) && cnt==grid[dx[k]][dy[k]])
                 {
                     q.push({dx[k],dy[k]});
                     break;
                 }
             }
         }
        if(cnt==(n*n))
        return true;
        return false;
    }
