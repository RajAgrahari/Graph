//Time : O(N+E) Space : O(N+E)+O(N)(visited)+O(N)(queue)
// first version: source is given and graph is connected
vector<int> bfsOfGraph(int source,int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> v;
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int cv = q.front();
            q.pop();
            v.push_back(cv);
            for(auto i=adj[cv].begin();i!=adj[cv].end();i++)
            {
                if(!visited[*i])
                {
                    q.push(*i);
                    visited[*i]=true;
                }
            }
        }
        return v;
    }
//second version : source is not given and graph may be disconnected
void bfsOfGraph2(int source,vector<int> adj[],vector<bool>& visited,vector<int>& ans) {
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int cv = q.front();
            q.pop();
            ans.push_back(cv);
            for(auto i=adj[cv].begin();i!=adj[cv].end();i++)
            {
                if(!visited[*i])
                {
                    q.push(*i);
                    visited[*i]=true;
                }
            }
        }
        return v;
    }
vector<int>  BFS(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        bfsOfGraph2(i,adj,visited,ans);
    }
    return ans;
}

