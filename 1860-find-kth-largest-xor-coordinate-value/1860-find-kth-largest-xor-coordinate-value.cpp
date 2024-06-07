class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(i) matrix[i][j]^=matrix[i-1][j];
                if(j) matrix[i][j]^=matrix[i][j-1];
                if(i&& j) matrix[i][j]^=matrix[i-1][j-1];
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
           
        } return pq.top();
    }
};