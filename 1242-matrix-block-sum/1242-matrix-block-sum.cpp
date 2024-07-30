/*
To extract sum of an arbitrary sub-array, we first form a prefix sum array.
[1, 2, 3, 4, 5] // original vector
[1, 3, 6, 10, 15] // prefix sum

To get sum of a sub array from index a to index b, sum(a, b), we can instead calculate prefix(b) - prefix(a-1)

Similar in 2D, we form prefix matrix, where sum[i][j] = sum of elements on top left of original matrix
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]

[1, 3, 6]
[5, 12, 21]
[12, 27, 45]

Similarly, Sum of an arbitrary block from (i-K, j-K) to (i+K, j+K)
ans(i, j) = prefix(i+K, j+K) - prefix(i+K, j-K-1) - prefix (i-K-1, j+K) + prefix(i-K-1, j-K-1);

*/

class Solution {
public:
   int PrefixSumFinder(int i, int j, vector<vector<int>>& sum){
    if(i<0 || j<0) return 0;
    if(i>=sum.size()) i=sum.size()-1;
    if(j>=sum[0].size()) j=sum[0].size()-1;
    return sum[i][j];
   }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>  prefix(n,vector<int>(m,0));
        // creating prefix sum matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j]=mat[i][j]+
                             PrefixSumFinder(i-1,j,prefix)+
                             PrefixSumFinder(i,j-1,prefix)-
                             PrefixSumFinder(i-1,j-1,prefix); // to avoid double counting
            }
        }

        // creating resultant matrix 
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=PrefixSumFinder(i+k,j+k,prefix)-
                          PrefixSumFinder(i+k,j-k-1,prefix)-
                          PrefixSumFinder(i-k-1,j+k,prefix)+
                          PrefixSumFinder(i-k-1,j-k-1,prefix);
            }
        }
       return ans;

    }
};