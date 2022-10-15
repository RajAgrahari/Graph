// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    vector<vector<int>> ans(n,vector<int>(m));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
                else
                visited[i][j] = false;
            }
        }
	    while(!q.empty())
	    {
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        ans[i][j] = d;
	        vector<int> row = {i-1,i+1,i,i};
	        vector<int> col = {j,j,j-1,j+1};
	        for(int k=0;k<4;k++)
	        {
	            if(row[k]>=0 && row[k]<n && col[k]>=0 && col[k]<m && visited[row[k]][col[k]]==false && grid[row[k]][col[k]]==0)
	            {
	                q.push({{row[k],col[k]},d+1});
	                visited[row[k]][col[k]]=true;
	            }
	        }
	    }
	    return ans;
	    
	}
