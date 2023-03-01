// https://leetcode.com/problems/word-ladder/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
         int l = beginWord.size();
         int ans=0;
         wordList.insert(wordList.begin(),beginWord);
         int n = wordList.size();
         int idx=-1;
         for(int i=0;i<n;i++)
         {
             if(wordList[i]==endWord)
             {
                 idx=i;
                 break;
             }
         }
         if(idx==-1)
         return 0;
         vector<int> adj[n];
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 int cnt=0;
                if(i!=j)
                for(int k=0;k<l;k++)
                {
                    if(wordList[i][k]==wordList[j][k])
                    cnt++;
                }
                if(cnt >= (l-1))
                adj[i].push_back(j);
             } 
         }
         queue<pair<int,int>> q;
         vector<bool> vis(n,false);
         q.push({0,1});
         vis[0]=true;
         
         while(!q.empty())
         {
             auto cv = q.front();
             q.pop();
             if(cv.first==(idx))
             {
                 ans = cv.second;
                 break;
             }
             for(auto it:adj[cv.first])
             {
                if(!vis[it])
                {
                    q.push({it,cv.second+1});
                    vis[it]=true;
                }
             }
         }
        return ans;

    }
