// just like triangle
// build path from bottom to top

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j-1<0) matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j+1]);
                else if(j+1>n-1) matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j-1]);
                else matrix[i][j]+=min(matrix[i+1][j-1],min(matrix[i+1][j],matrix[i+1][j+1]));
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,matrix[0][j]);
        }

        return ans;
    }
};