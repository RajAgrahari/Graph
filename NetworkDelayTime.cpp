// https://leetcode.com/problems/network-delay-time/
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> edges[n+1];
        for(int i=0;i<times.size();i++)
        edges[times[i][0]].push_back({times[i][1],times[i][2]});
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	    distTo[k] = 0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            for(auto itr:edges[it.second])
            {
                int next = itr.first;
			    int nextDist = itr.second;
			    if( distTo[next] > distTo[it.second] + nextDist)
			    {
				   distTo[next] = distTo[it.second] + nextDist;
				   pq.push({distTo[next], next});
			    }
            }
        }
        int m = -1;
        for(int i=1;i<=n;i++)
        {
            if(distTo[i]!=INT_MAX)
            {
                m = max(m,distTo[i]);
            }
            else
            return -1;
        }
        return m;

    }
