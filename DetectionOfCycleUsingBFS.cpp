//Time : O(V+E) and Space : O(V)
bool detectCycle(vector<int> adj[],int i,vector<bool>& visited,int V)
    {
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i]=true;
        while(!q.empty())
        {
            int n = q.front().first;
            int p = q.front().second;
            q.pop();
            for(auto i:adj[n])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push({i,n});
                }
                else if(p!=i)
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(adj,i,visited,V))
                return true;
            }
        }
        return false;
        
         
    }