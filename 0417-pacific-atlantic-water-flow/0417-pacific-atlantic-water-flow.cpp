class Solution {
public:
    // make 2 matrix of same dimensions as m*n for pacific  and atlantic ocean
    //mark the cells as 1 if water can reach from oceans to  these cells
    //common cells  with 1 value in both the matrices are the answers

   
    void filling(vector<vector<int>>& heights, vector<vector<int>>& matrix,int i, int j,int prev){
        //think in reverse order 
        // i.e think about water flowing from oceans to cells
        int n=heights.size();
        int m=heights[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1) return;   
        if(matrix[i][j]==1) return;
        if(heights[i][j]<prev) return;
        matrix[i][j]=1;
        filling(heights,matrix,i-1,j,heights[i][j]);
        filling(heights,matrix,i+1,j,heights[i][j]);
        filling(heights,matrix,i,j-1,heights[i][j]);
        filling(heights,matrix,i,j+1,heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            filling(heights,pacific,0,j,INT_MIN);
            filling(heights,atlantic,n-1,j,INT_MIN);
        }
        for(int i=0;i<n;i++){
            filling(heights,pacific,i,0,INT_MIN);
             filling(heights,atlantic,i,m-1,INT_MIN);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                   ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};