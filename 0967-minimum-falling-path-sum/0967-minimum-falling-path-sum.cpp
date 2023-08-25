class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int small=INT_MAX;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
             matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j+1]); 
                } 
                else if(j==n-1)
                {
         matrix[i][j]+=min(matrix[i+1][j-1],matrix[i+1][j]);
                }
                else{
            matrix[i][j]+=min(matrix[i+1][j-1],min(matrix[i+1][j],matrix[i+1][j+1]));
                }

            }
        }

        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]<small)
            {
                small=matrix[0][j];
            }
        }
        return small;
    }

};