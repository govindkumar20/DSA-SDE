class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        long long countNegatives=0;
        long long mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) countNegatives++;
                if(mini>abs(matrix[i][j])) mini=abs(matrix[i][j]);
            }
        }
        if(countNegatives%2==0) return sum;
        return sum-(mini*2);
    }
};