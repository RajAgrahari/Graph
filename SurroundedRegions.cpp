// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
 void dfs(int i,int j,int n,int m,vector<vector<char>>& mat,vector<vector<bool>>& visited)
     {
           visited[i][j]=true;
           vector<int> row = {i,i,i-1,i+1};
           vector<int> col = {j-1,j+1,j,j};
           for(int k=0;k<4;k++)
           {
               if(row[k]<n && row[k]>=0 && col[k]<m && col[k]>=0 && !visited[row[k]][col[k]] && mat[row[k]][col[k]]=='O')
               {
                   dfs(row[k],col[k],n,m,mat,visited);
               }
           }
      }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int j = 0 ; j<m;j++) {
            if(!visited[0][j] && mat[0][j] == 'O') {
                dfs(0,j,n,m,mat, visited);  
            }
            
            if(!visited[n-1][j] && mat[n-1][j] == 'O') {
               dfs(n-1,j,n,m,mat, visited); 
            }
        }
        for(int j = 0 ; j<n;j++) {
            if(!visited[j][0] && mat[j][0] == 'O') {
                dfs(j,0,n,m,mat, visited); 
            }
            
            if(!visited[j][m-1] && mat[j][m-1] == 'O') {
                dfs(j,m-1,n,m,mat, visited); 
            }
        }
         for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!visited[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return mat; 
        
    }
