//https://practice.geeksforgeeks.org/problems/7e5ec07f9d865297cff9a91522c2ce805433b420/1
 bool check(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({start_x,start_y});
        vis[start_x][start_y]=true;
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, 2, -2, 1, -1};
        vector<int> coin_arr;
        while(!q.empty())
        {
            int coins=0;
            int size = q.size();
            while(size--)
            {
                auto it = q.front();
                q.pop();
                coins += arr[it.first][it.second];
                for(int k=0;k<8;k++)
                {
                    int x = it.first + dx[k];
                    int y = it.second + dy[k];
                    if(check(x,y,n,m) && !vis[x][y])
                    {
                        q.push({x,y});
                        vis[x][y] = true;
                    }
                }
            }
            coin_arr.push_back(coins);
            
        }
        int ans=0;
        int mx = INT_MIN;
        for(int i=coin_arr.size()-1;i>=0;i--)
        {
            if(coin_arr[i]+i<coin_arr.size())
            {
                coin_arr[i] += coin_arr[coin_arr[i]+i];
            }
            if(coin_arr[i]>=mx)
            {
                mx = coin_arr[i];
                ans=i;
            }
        }
        return ans;
    }
