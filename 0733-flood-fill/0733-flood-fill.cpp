class Solution {
public:
    void dfs(vector<vector<int>>& image, int i,int j,int color,int starting_color){
        int n=image.size();
        int m=image[0].size();
        if(i<0 || j<0 || i==n || j==m || image[i][j]==color|| image[i][j]!=starting_color) return;
        image[i][j]=color;
       dfs(image,i-1,j,color,starting_color);
       dfs(image,i+1,j,color,starting_color);
       dfs(image,i,j-1,color,starting_color);
        dfs(image,i,j+1,color,starting_color);
    }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // simple dfs hai , basically neighbours updation
        int starting_color=image[sr][sc];
        if (starting_color != color) {
            dfs(image, sr, sc, color, starting_color);
        }
        return image;
    }
};