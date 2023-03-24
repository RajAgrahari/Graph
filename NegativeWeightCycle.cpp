//https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int> dis(n,1e8);
	    dis[0]=0;
	    for(int j=0;j<n;j++)
	    {
	        for(auto i:edges)
	        {
	            if(dis[i[1]]>dis[i[0]]+i[2])
	            {
	                dis[i[1]]=dis[i[0]]+i[2];
	            }
	        }
	    }
	    for(auto i:edges)
	    {
	        if(dis[i[1]]>dis[i[0]]+i[2])
	        {
	           return true;
	        }
	    }
	    return false;
	    
	}
