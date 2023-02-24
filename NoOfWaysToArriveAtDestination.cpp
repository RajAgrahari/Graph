// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
int mod = 1e9 + 7;
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> edges[n];
        for(int i=0;i<roads.size();i++)
        {
            edges[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            edges[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> distTo(n,LONG_MAX);
        vector<ll> ways(n,0);
	    distTo[0] = 0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            for(auto itr:edges[it.second])
            {
                int next = itr.first;
			    int nextDist = itr.second;
			    if( distTo[next] > it.first + nextDist)
			    {
				   distTo[next] = it.first + nextDist;
                   ways[next] = ways[it.second];
				   pq.push({distTo[next], next});
			    }
                else if(distTo[next]==it.first+nextDist)
                ways[next] = (ways[next] + ways[it.second])%mod;
            }
        }
        return ways[n-1];
    }
