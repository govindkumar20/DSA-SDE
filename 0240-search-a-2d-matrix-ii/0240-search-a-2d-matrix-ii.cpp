class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ri=0;
        int ci=col-1;
        while(ri<row && ci>=0)
        {
            if(matrix[ri][ci]==target) return true;
            (matrix[ri][ci]>target)?ci--:ri++;    
        }
        return false;
    }
};