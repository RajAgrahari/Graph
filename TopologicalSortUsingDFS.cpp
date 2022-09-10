	void dfstoposort(vector<int> adj[],int i,vector<int>& visited,stack<int>& s)
	{
	    visited[i]=1;
	    for(auto it:adj[i])
	    {
	        if(!visited[it])
	        {
	            visited[it]=1;
	            dfstoposort(adj,it,visited,s);
	        }
	    }
	    s.push(i);
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        dfstoposort(adj,i,visited,s);
	    }
	    for(int i=0;i<V;i++)
	    {
	       visited[i]=s.top();
	       s.pop();
	    }
	    return visited;
	    
	    
	}