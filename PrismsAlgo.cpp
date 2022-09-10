//Time : O(V*2)
int prismAlgo(int graph[V][], int V)
{
   vector<int> key(V,INT_MAX);
   vector<int> parent(V, -1);
   key[0]=0;
   vector<bool> mset(V, false);
   int res=0;
   for(int count=0;count<V;count++)
   {
      int u=-1;
      for(int i=0;i<V;i++)
      {
         if(!mset[i] && (u==-1 || key[i]<key[u]))
         u=i;
      }
      mset[i]=true;
      res=res+key[u];
      for(int v=0;v<V;i++)
      {
         if(graph[u][v]!=0 && !mset[v])
         {
            key[v]=min(key[v],graph[u][v]);
            parent[v]=u;
         }
      }
   }
   return res;
}
//for adjacency list representation above algo is:-
for(int i=0;i<edges;i++)
{
    cin>>a>>b>>wt;
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
}
int prismAlgo(vector<pair<int,int>> adj[], int V)
{
   vector<int> key(V,INT_MAX);
   vector<int> parent(V, -1);
   key[0]=0;
   vector<bool> mset(V, false);
   int res=0;
   for(int count=0;count<V;count++)
   {
      int u=-1;
      for(int i=0;i<V;i++)
      {
         if(!mset[i] && key[i]<key[u])
         u=i;
      }
      mset[i]=true;
      res=res+key[u];
      for(auto it:adj[u])
      {
        int v = it.first;
        int weight = it.second;
         if(!mset[v] && weight<key[v])
         {
            key[v]=weight;
            parent[v]=u;
         }
      }
      //for printing MST
      for(int i=0;i<V;i++)
      {
        cout<<parent[i]<<"-"<<i<<endl;
      }
   }
   return res;
}
//Efficient approach
//Time : O(E*log(V))
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({key[0], 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		          key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
