//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> indegree(n);
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
               ans.push_back(i);
            }
        }
        if(ans.size()==0)
        ans.push_back(0);
        return ans;


    }
