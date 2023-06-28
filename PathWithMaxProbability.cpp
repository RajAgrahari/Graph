//https://leetcode.com/problems/path-with-maximum-probability/
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans=0;
        priority_queue<pair<double, int>>q;
        q.push({1, start});
        vector<pair<int, double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>v(n, 0);
        v[start]=1;
        while(!q.empty()){
            int pos=q.top().second;
            double cnt=q.top().first;
            q.pop();
            if(pos==end){ans=max(ans, cnt);}
            for(auto it: adj[pos]){
                if(cnt*it.second>v[it.first]){
                    v[it.first]=(double)cnt*it.second;
                    q.push({v[it.first], it.first});
                }
            }
        }
        return ans;
    }
