//https://leetcode.com/problems/evaluate-division/description/
bool dfs(string x,string y,unordered_map<string,vector<pair<string,double>>>& mp,unordered_map<string,bool> mp1,double& ans)
    {
         if(mp.count(x) && mp.count(y) && x==y)
         {
            return true;
         }
         mp1[x] = true;
        for(auto it:mp[x]) 
        {
            if(!mp1[it.first])
            {
                ans *= it.second;
                if(dfs(it.first,y,mp,mp1,ans))
                return true; 
                else
                ans /= it.second;   
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string,vector<pair<string,double>>> mp;
        int n = equations.size();
        for(int i=0;i<n;i++)
        {
           mp[equations[i][0]].push_back({equations[i][1],values[i]});
           mp[equations[i][1]].push_back({equations[i][0],((double)1/values[i])});
        }
        int m = queries.size();
        vector<double> res;
        for(int i=0;i<m;i++)
        {
            string x = queries[i][0];
            string y = queries[i][1];
            unordered_map<string,bool> mp1;
            double ans=1;
            if(dfs(x,y,mp,mp1,ans))
            res.push_back(ans);
            else
            res.push_back(-1);
        }
        return res;
    }
