//https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1
void dfs(unordered_map<char,bool>&visited, unordered_map<char,vector<char>>&mp, char s)
    {
        if(mp[s].size()==0)
        return;
        visited[s]=true;

        for(auto x:mp[s])
        {
             if(!visited[x])
             {
                dfs(visited,mp,x);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {

        if (N==1 and A[0][0]!=A[0][A[0].length()-1])return false;

        unordered_map<char,vector<char>>mp;
        int in[26]={0};
        int out[26]={0};
        unordered_map<char,bool>visited;

        for(auto x:A){

            mp[x[0]].push_back(x[x.size()-1]);
            in[x[x.size()-1]-'a']++;
            out[x[0]-'a']++;

        }
         for(int i=0;i<26;i++) 
         if(in[i] != out[i]) 
         return 0;
        for(auto x:A){

            if(!visited[x[0]]){

                dfs(visited,mp,x[0]);

            }
            for(auto c:A)
            {
                if(!visited[c[0]] or !visited[c[c.length()-1]])
                {
                    return 0;
                }
            }
            return 1;
            break;

        }

    }
