 bool isSafe(int x, int y, int n, vector<vector<int>>& vis){
       
       if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]==0){
           return true;
       }
       return false;
   }
   int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> visited(N,vector<int>(N,0));
	    int x = KnightPos[0]-1;
        int y = KnightPos[1]-1;
        
        int tx = TargetPos[0]-1;
        int ty = TargetPos[1]-1;
        
        if(x==tx && y==ty){
               return 0;
           }
        
        //direction guides
        int dx[] = {2,2,-2,-2,1,-1,1,-1};
        int dy[] = {1,-1,1,-1,2,2,-2,-2};
        
        //make a queue
        
        q.push({{x,y},0});
        visited[x][y] = 1;
        
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            
            int nx = p.first.first;
            int ny = p.first.second;
            int currDist = p.second;
            
            q.pop();
            
            for(int i=0;i<8;i++){
                int x = nx+dx[i];
                int y = ny+dy[i];
                
                if(x==tx && y==ty)
                {
                    return currDist+1;
                }
                
                if(isSafe(x,y,N,visited)){
                    visited[x][y]=1;
                    q.push({{x,y},currDist+1});
                }
            }
        }
        return -1;
	}