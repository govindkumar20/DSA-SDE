class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    void dfs(int i, int j, vector<vector<int>>& image,int startingColor, int color){
        int n=image.size();
        int m=image[0].size();
        if(i>=0 && i<=n-1 && j>=0 && j<=m-1 && image[i][j]==startingColor && image[i][j]!=color) {
            image[i][j]=color;
            for(int p=0;p<4;p++){
                dfs(i+xm[p],j+ym[p],image,startingColor,color);
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int startingColor=image[sr][sc];
        dfs(sr,sc,image,startingColor,color);
        return image;
    }
};