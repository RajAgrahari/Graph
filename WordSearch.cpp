//https://practice.geeksforgeeks.org/problems/word-search/1
bool check(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    bool dfs(int i,int j,int k,int n,int m,vector<vector<char>>& board,string word)
    {
        if(k==word.size())
        return true;
        int dx[] = {i-1,i+1,i,i};
        int dy[] = {j,j,j-1,j+1};
        char temp = board[i][j];
        board[i][j] = '#';
        for(int t=0;t<4;t++)
        {
            if(check(dx[t],dy[t],n,m) && word[k]==board[dx[t]][dy[t]])
            {
                if(dfs(dx[t],dy[t],k+1,n,m,board,word))
                return true;
            }
        }
        board[i][j] = temp;
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,1,n,m,board,word))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
