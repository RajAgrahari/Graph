//https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
int isEularCircuit(int V, vector<int>adj[])
	{
	     int count = 0;
        for(int i=0; i<V; i++)
        {
            if(adj[i].size()%2==1)
            {
                count++;
            }
        }
        
        if(count==0) return 2;
        else if(count==2) return 1;
        else return 0;
	}
