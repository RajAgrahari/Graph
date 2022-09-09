// Time: O(V+E) and Space: O(V)(visited)
bool detectCycle(vector<int> adj[],int i,int parent,vector<bool>& visited,int V)
    {
        visited[i]=true;
            for(auto it:adj[i])
            {
                if(!visited[it])
                {
                    if(detectCycle(adj,it,i,visited,V))
                    return true;
                }
                else if(it!=parent)
                return true;
            }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(adj,i,-1,visited,V))
                return true;
            }
        }
        return false;
        
         
    }