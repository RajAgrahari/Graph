vector<int> toposort(int V,vector<int> adj[])
{ 
           queue<int> q;
           vector<int> indegree(V,0);
           vector<int> topo;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
              indegree[it]++;
            }
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            topo.push_back(x);
            for(auto it:adj[x])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return topo;
}
        