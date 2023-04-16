//https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
vector<pair<int,int>> graph[101];
    int limit;
    Graph(int n, vector<vector<int>>& edges) 
    {
          limit=n;
         for(int i=0;i<edges.size();i++)
         {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         } 
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dis(limit+1,LONG_MAX);
        dis[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int dist=pq.top().first;
            int n=pq.top().second;
            pq.pop();
            for(auto it:graph[n]){
                if(dist+it.second<dis[it.first])
                {
                    dis[it.first]=dist+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        if(dis[node2]==LONG_MAX) 
        return -1;
        return dis[node2];
    }
