//Time: O(N+E) Space:O(N)(visited array)+O(N)(dfsvisited) AuxilliarySpace: O(N)(function calls)
bool detectCycledfs(int i,vector<int> adj[],vector<bool>& visited,vector<bool>& dfsvisited)
     {
        visited[i]=true;
        dfsvisited[i]=true;
        for(auto it:adj[i])
        {
            if(!visited[it])
            {
                if(detectCycledfs(it,adj,visited,dfsvisited))
                return true;
            }
            else if(dfsvisited[it])
            return true;
        }
        dfsvisited[i]=false;
        return false;
     }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> dfsvisited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycledfs(i,adj,visited,dfsvisited))
                return true;
            }
        }
        return false;
    }