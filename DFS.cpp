//Time: O(N+E) Space:O(N)(visited array) AuxilliarySpace: O(N)(function calls)
void dfsrec(vector<int>adj[],int src,vector<int>& vs,vector<bool>& visited)
      {
          visited[src]=true;
          vs.push_back(src);
          for(int x:adj[src])
              if(visited[x]==false)
              dfsrec(adj,x,vs,visited);
      }
     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
       vector<int> vs;
       
        dfsrec(adj,0,vs,visited);
       return vs;
   
    }