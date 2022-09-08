// https://leetcode.com/problems/flood-fill/
 void dfs(vector<vector<int>>& image, int sr, int sc,int sourceColor,int color)
    {
        image[sr][sc]=color;
        vector<int>row = {sr + 1, sr - 1, sr, sr};
        vector<int>col = {sc, sc, sc + 1, sc - 1};
        for(int k = 0; k < 4; k++){
            if(row[k] < image.size() && col[k] < image[0].size() && row[k] >= 0 && col[k] >= 0 
                && image[row[k]][col[k]] == sourceColor){
                dfs(image, row[k], col[k],sourceColor,color);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sourceColor = image[sr][sc];
        if(color==sourceColor)
            return image;
        dfs(image,sr,sc,sourceColor,color);
        return image;
    }